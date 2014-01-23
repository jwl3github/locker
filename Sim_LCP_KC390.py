from Tkinter import *
import Tkinter as tk
import sys
import time
from Sim_UDP_Channel import *

CP_SIM = None

## This 2-channel design may be over-kill, but concerned that the
## eventual inclusion of the CHC may require the separation.
##
## Further, exerting system control via an external Monitor/Injector
## tool may complicate things even more.

DATA_CHANNEL = None

# ==============================================================================
# TX
# ==============================================================================
def Send_T_LCU_Status_Request_Message():
    msg = 'T_LCU_Status_Request_Message'
    DATA_CHANNEL.Send_Tx(msg)
# ------------------------------------------------------------------------------
def Send_T_LCU_Bit_Request(): #lock_id, act_ibit, act_state, sol_ibit, sol_state):
        #    Lock_1_Actuator_Serial_Switch_IBIT;
        #    Lock_2_Actuator_Serial_Switch_IBIT;
        #    Lock_1_Actuator_Serial_Switch_State;
        #    Lock_2_Actuator_Serial_Switch_State;
        #    Lock_1_Solenoid_Serial_Switch_IBIT;
        #    Lock_2_Solenoid_Serial_Switch_IBIT;
        #    Lock_1_Solenoid_Serial_Switch_State;
        #    Lock_2_Solenoid_Serial_Switch_State;
    msg = 'T_LCU_BIT_Request_Message'
    DATA_CHANNEL.Send_Tx(msg)
# ------------------------------------------------------------------------------
def Send_T_LCU_Set_Lock_State_Command_Message(lock_id, state):

    # JWL: TODO Is there a design issue/opportunity here?
# TODO any given LCU will only care about a pair of lock states, and furthermore
# TODO any given CP can only control a pair as well.
# TODO My guess is that the Dest_ID controls how the message is used, but
# TODO this still represents quite a bit of mis-information floating around.
# TODO why not 'UINT16 Lock_A_Id; UINT16 Lock_A_State; UINT16 Lock_B_Id; UINT16 Lock_B_State'
# TODO or even notice BIT Req just calls them 'Lock_1/Lock_2' so no need for '_Id'
    msg  = 'T_LCU_Set_Lock_State_Command_Message,'
    msg += 'Lock_%d_State=%s,' % (lock_id, state)
    DATA_CHANNEL.Send_Tx(msg)
# ------------------------------------------------------------------------------
def Send_T_LCU_Force_Request_Message():
    msg = 'T_LCU_Force_Request_Message'
    DATA_CHANNEL.Send_Tx(msg)
# ==============================================================================
# RX
# ==============================================================================
def Recv_T_LCU_Status_Response_Message(msg):
    # UINT8                BIT_Passed;
    # UINT16               Lock_Sensor_Count;
    # T_Lock_Sensor_Data  * Lock_Sensor_Data;
    #     typedef struct {
    #         UINT8                Lock_Busy;
    #         UINT16               Lock_State;
    #         UINT16               Next_Lock_State;
    #     } T_Lock_Sensor_Data;
    CP_SIM.set_state('AFT',   'UNLOCKED')
    CP_SIM.set_state('FWD',   'UNLOCKED')
    CP_SIM.set_state('CRG_L', 'UNLOCKED')
    CP_SIM.set_state('CRG_R', 'UNLOCKED')
# ------------------------------------------------------------------------------
def Recv_T_LCU_BIT_Response_Message(msg):
    print msg
    # Overall_BIT_Passed;
    # Actuator_Extended;
    # Actuator_Retracted;
    # Capacitor_Charge_Disable;
    # Capacitor_Charge_State;
    # Actuator_Current;
    # Lock_Dog_Location_Sensor;
    # Lock_Dog_Displacement_Force_Sensor;
    # ADS_Trigger_Location_Sensor;
    # LCU_Point_of_Load_Power_Fault;
    # Actuator_Power_Enable_Serial_Switch_Fault;
    # Actuator_Extend_Serial_Switch_Fault;
    # Actuator_Retract_Serial_Switch_Fault;
    # Capacitor_Charge_Fault;
    # Reset_Fault;
    # Communications_Fault;
    # Actuator_Serial_Switch_State;
    # Solenoid_Serial_Switch_State;
# ------------------------------------------------------------------------------
def Recv_T_LCU_BIT_Response_Message(msg):
    print msg
    # Lock_1_Dog_Displacement_Force_Sensor;
    # Lock_2_Dog_Displacement_Force_Sensor;
# ------------------------------------------------------------------------------
def Recv_Message(msg):
    print 'Recv_Message - ' + msg
    if msg.startswith('T_LCU_Status_Response_Message'):
        Recv_T_LCU_Status_Response_Message(msg)
    elif msg.startswith('T_LCU_BIT_Response_Message'):
        Recv_T_LCU_BIT_Response_Message(msg)
    elif msg.startswith('T_LCU_Force_Response_Message'):
        Recv_T_LCU_Force_Response_Message(msg)
    else:
        print 'Recv_Message - huh? ' + msg

# ##############################################################################
class CP_Label(Label):
    def __init__(self, parent, grid_row, lock_id, grp_id):
        Label.__init__(self, parent, text="[%d.%s]" % (lock_id, grp_id))
        self.grid(row=grid_row, column=0)
        self.lock_id = lock_id
        self.grp_id  = grp_id
# ##############################################################################
class CP_Button(Button):
    def __init__(self, parent, grid_row, lock_id, state):
        Button.__init__(self, parent, width=20, bg='gray', command=self.click)
        self.grid(row=grid_row, column=1)
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
                             'REQ_STAT' :'REQ_STAT',            # Manual control of LCU Status Request
                             'REQ_BIT'  :'REQ_BIT',             # Manual control of LCU BIT Request
                             'REQ_FORCE':'REQ_FORCE',           # Manual control of LCU Force Request
                            }
        self.colors       = {'ARMED'    :'gray',
                             'LOCKED'   :'green',
                             'UNLOCKED' :'yellow',
                             'FAIL_0'   :'red',
                             'FAIL_1'   :'gray',
                             'NO_TEST'  :'gray',
                             'TEST'     :'white',
                             'TESTING'  :'white',
                             'REQ_STAT' :'white',
                             'REQ_BIT'  :'white',
                             'REQ_FORCE':'white',
                            }
        self.state_change = {'ARMED'    :'ARMED',      # Supposed to wait for control message before going to init locked/unlocked.
                             'LOCKED'   :'UNLOCKED',
                             'UNLOCKED' :'LOCKED',
                             'FAIL_0'   :'FAIL_1',
                             'FAIL_1'   :'FAIL_0',
                             'NO_TEST'  :'TEST',
                             'TEST'     :'NO_TEST',
                             'TESTING'  :'TESTING',
                             'REQ_STAT' :'REQ_STAT',
                             'REQ_BIT'  :'REQ_BIT',
                             'REQ_FORCE':'REQ_FORCE',
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
            if self.state in ('LOCKED', 'UNLOCKED', 'ARMED'):
                Send_T_LCU_Set_Lock_State_Command_Message(self.lock_id, self.state)
            elif self.state == 'REQ_STAT':
                Send_T_LCU_Status_Request_Message()
            elif self.state == 'REQ_BIT':
                Send_T_LCU_Bit_Request()
            elif self.state == 'REQ_FORCE':
                Send_T_LCU_Force_Request_Message()
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
# ##############################################################################
class Sim_LCP_KC390(Frame):
    def __init__(self, parent, first_lock_id, lcp_type):
        '''size is the size of a square, in pixels'''
        self.lbl, self.btn      = {}, {}
        self.testing            = False
        self.first_lock_id      = first_lock_id
        self.lbl['REQ_STAT']    = CP_Label  (parent,  0, -1,              'REQ_STAT')
        self.btn['REQ_STAT']    = CP_Button (parent,  0, -1,              'REQ_STAT')
        self.lbl['REQ_BIT']     = CP_Label  (parent,  1, -1,              'REQ_BIT')
        self.btn['REQ_BIT']     = CP_Button (parent,  1, -1,              'REQ_BIT')
        self.lbl['REQ_FORCE']   = CP_Label  (parent,  2, -1,              'REQ_FORCE')
        self.btn['REQ_FORCE']   = CP_Button (parent,  2, -1,              'REQ_FORCE')
        self.lbl['TEST']        = CP_Label  (parent,  3, first_lock_id,   'TEST')
        self.btn['TEST']        = CP_Button (parent,  3, first_lock_id,   'NO_TEST')
        self.lbl['AFT']         = CP_Label  (parent,  4, first_lock_id+1, 'AFT')
        self.btn['AFT']         = CP_Button (parent,  4, first_lock_id+1, 'ARMED')
        self.lbl['FWD']         = CP_Label  (parent,  5, first_lock_id,   'FWD')
        self.btn['FWD']         = CP_Button (parent,  5, first_lock_id,   'ARMED')
        if lcp_type == 1:
            self.lbl['CRG_L']   = CP_Label  (parent,  6, first_lock_id+1, 'CRG_L')
            self.btn['CRG_L']   = CP_Button (parent,  6, first_lock_id+1, 'ARMED')
            self.lbl['CRG_R']   = CP_Label  (parent,  7, first_lock_id,   'CRG_R')
            self.btn['CRG_R']   = CP_Button (parent,  7, first_lock_id,   'ARMED')

        #r = 0
        #for grp in ('REQ_STAT', 'REQ_BIT', 'REQ_FORCE', 'TEST', 'AFT', 'FWD', 'CRG_L', 'CRG_R'):
        #     self.lbl[grp].grid(row=r, column=0, sticky=W)
        #     self.btn[grp].grid(row=r, column=1)
        #     r += 1

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
def main(args):
    global CP_SIM, DATA_CHANNEL

    # TODO read from args
    first_lock_id = 1
    lru_id        = 21  # TODO value is faked one for CP-1
    lcp_type      = 1

    DATA_CHANNEL = Sim_UDP_Channel('224.1.1.2', 5007,  # Tx: CP (Master) Command channel
                                   '224.1.1.1', 5006)  # Rx: LCU (Slave) Response channel
    DATA_CHANNEL.Start_Tx()
    DATA_CHANNEL.Start_Rx(Recv_Message)

    tk_root = Tk()
    tk_root.wm_title('CP for Lock %d/%d' % (first_lock_id, first_lock_id+1))

    CP_SIM = Sim_LCP_KC390(tk_root, first_lock_id, lcp_type)

    tk_root.mainloop()
# ------------------------------------------------------------------------------
if __name__ == "__main__":
    main(sys.argv[1:])
