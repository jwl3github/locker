from Tkinter import *
import Tkinter as tk
import socket
import struct
import threading
import time

rx_sock = None
tx_sock = None
lcp_sim = None

# ##############################################################################

class CP_Label(Label):
    def __init__(self, parent, lock_id, grp_id):
        Label.__init__(self, parent, text="[%d.%s]" % (lock_id, grp_id))
        self.lock_id = lock_id
        self.grp_id  = grp_id
# ==============================================================================
class CP_Button(Button):
    def __init__(self, parent, lock_id, state):
        Button.__init__(self, parent, width=20, bg='gray', command=self.click)
        self.lock_id      = lock_id
        self.state        = state
        self.timer_id     = None
        self.handler      = None
        self.text         = {'ARMED'    :'ARMED',
                             'LOCKED'   :'LOCKED',
                             'UNLOCKED' :'UNLOCKED',
                             'FAIL_0'   :'LOCKED | UNLOCKED',
                             'FAIL_1'   :'LOCKED | UNLOCKED',
                             'NO_TEST'  :'NO_TEST',             # Annun
                             'TEST'     :'TEST',                # Annun
                             'TESTING'  :'LOCKED | UNLOCKED',   # Button during test on
                            }
        self.colors       = {'ARMED'    :'gray',
                             'LOCKED'   :'green',
                             'UNLOCKED' :'yellow',
                             'FAIL_0'   :'red',
                             'FAIL_1'   :'gray',
                             'NO_TEST'  :'gray',
                             'TEST'     :'white',
                             'TESTING'  :'white',
                            }
        self.state_change = {'ARMED'    :'ARMED',      # Supposed to wait for control message before going to init locked/unlocked.
                             'LOCKED'   :'UNLOCKED',
                             'UNLOCKED' :'LOCKED',
                             'FAIL_0'   :'FAIL_1',
                             'FAIL_1'   :'FAIL_0',
                             'NO_TEST'  :'TEST',
                             'TEST'     :'NO_TEST',
                             'TESTING'  :'TESTING',
                             }
        self.update_display(self.state)
# ------------------------------------------------------------------------------
    def update_display(self, state):
        self.configure(text=self.text[state], bg=self.colors[state])
# ------------------------------------------------------------------------------
    def set_test(self, enabled):
        if enabled:
            self.update_display('TESTING')
        else:
            self.update_display(self.state)
# ------------------------------------------------------------------------------
    def set_state(self, state):
        if self.text.has_key(state):
            self.state = state
            self.update_display(self.state)
            print 'Set => new state for <%s> = <%s>' % (self.lock_id, self.state)
        else:
            self.state = 'FAIL_0'
            self.update_display(self.state)
            self.timer()
            print 'Set => BAD state for <%s> = <%s>' % (self.lock_id, self.state)
# ------------------------------------------------------------------------------
    def click(self):
        if self.state_change.has_key(self.state):
            self.state = self.state_change[self.state]
            self.update_display(self.state)
            print 'Click => new state for <%s> = <%s>' % (self.lock_id, self.state)
        else:
            print 'Click => BAD state for <%s> = <%s>' % (self.lock_id, self.state)
            self.state = 'FAIL_0'
            self.update_display(self.state)
            self.timer()
        if self.handler:
            self.handler()
# ------------------------------------------------------------------------------
    def set_click_handler(self, handler):
        self.handler = handler
# ------------------------------------------------------------------------------
    def timer(self):
        if self.state_change.has_key(self.state):
            self.state = self.state_change[self.state]
            self.update_display(self.state)
        #if not self.timer_id:
            self.timer_id = self.after(500, self.timer)
# ------------------------------------------------------------------------------
    def cancel_timer(self):
        if self.timer_id:
            self.after_cancel(self.timer_id)
            self.timer_id = None
# ==============================================================================
class Sim_LCP_KC390(Frame):
    def __init__(self, parent, first_lock_id, lcp_type):
        '''size is the size of a square, in pixels'''
        self.lbl, self.btn      = {}, {}
        self.testing            = False
        self.first_lock_id      = first_lock_id
        self.lbl['TEST']        = CP_Label  (parent, first_lock_id,   'TEST')
        self.btn['TEST']        = CP_Button (parent, first_lock_id,   'NO_TEST')
        self.lbl['AFT']         = CP_Label  (parent, first_lock_id+1, 'AFT')
        self.btn['AFT']         = CP_Button (parent, first_lock_id+1, 'ARMED')
        self.lbl['FWD']         = CP_Label  (parent, first_lock_id,   'FWD')
        self.btn['FWD']         = CP_Button (parent, first_lock_id,   'ARMED')
        if lcp_type == 1:
            self.lbl['CRG_L']   = CP_Label  (parent, first_lock_id+1, 'CRG_L')
            self.btn['CRG_L']   = CP_Button (parent, first_lock_id+1, 'ARMED')
            self.lbl['CRG_R']   = CP_Label  (parent, first_lock_id,   'CRG_R')
            self.btn['CRG_R']   = CP_Button (parent, first_lock_id,   'ARMED')

        r = 0
        for grp in ('TEST', 'AFT', 'FWD', 'CRG_L', 'CRG_R'):
             self.lbl[grp].grid(row=r, column=0, sticky=W)
             self.btn[grp].grid(row=r, column=1)
             r += 1

        self.btn['TEST'].set_click_handler(self.click_test)
# ------------------------------------------------------------------------------
    def set_state(self, grp_id, state):
        self.btn[grp_id].set_state(state)
# ------------------------------------------------------------------------------
    def click_test(self):
        self.testing = not self.testing
        for grp in ('AFT', 'FWD', 'CRG_L', 'CRG_R'):
            self.btn[grp].set_test(self.testing)
        #self.btn['RIGHT'].set_state('bad-state')   ## Demo of flashing fail
# ##############################################################################
def Tx_UDP(msg):
    MCAST_GRP = '224.1.1.2'
    MCAST_PORT = 5007 # LCP is master:  Tx on port=5007, Rx on port=5006
    global tx_sock
    if tx_sock is None:
        tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        tx_sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 2)
    print '  .. Master Sending: ' + msg
    tx_sock.sendto(msg, (MCAST_GRP, MCAST_PORT))
# ##############################################################################
def Rx_UDP():
    global rx_sock
    while True:
        try:
            MCAST_GRP = '224.1.1.1'
            MCAST_PORT = 5006 # LCP is master:  Tx on port=5007, Rx on port=5006
            rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
            rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            rx_sock.bind(('', MCAST_PORT))
            mreq = struct.pack("4sl", socket.inet_aton(MCAST_GRP), socket.INADDR_ANY)
            rx_sock.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)
            print 'master CP listener connected!'
            break
        except:
            print 'master CP listener retry...'
            pass
    while True:
        print 'master CP listening...'
        msg = rx_sock.recv(10240)
        if msg == 'slave-is-ready':
            lcp_sim.set_state('AFT',   'UNLOCKED')
            lcp_sim.set_state('FWD',   'UNLOCKED')
            lcp_sim.set_state('CRG_L', 'UNLOCKED')
            lcp_sim.set_state('CRG_R', 'UNLOCKED')
# ##############################################################################
if __name__ == "__main__":
    listen_thread = threading.Thread(target = Rx_UDP)
    listen_thread.start()

    global lcp_sim
    tk_root       = Tk()
    first_lock_id = 1
    lcp_type      = 1
    lcp_sim       = Sim_LCP_KC390(tk_root, first_lock_id, lcp_type)
    Tx_UDP('startup')
    tk_root.mainloop()

