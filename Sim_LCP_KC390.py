from Tkinter import *
import Tkinter as tk

# ==============================================================================
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
# ==============================================================================
if __name__ == "__main__":
    tk_root       = Tk()
    first_lock_id = 1
    lcp_type      = 1
    lcp_sim       = Sim_LCP_KC390(tk_root, first_lock_id, lcp_type)
    tk_root.mainloop()

