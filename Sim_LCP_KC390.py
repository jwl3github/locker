from Tkinter import *
import Tkinter as tk
import sys
import time
from Sim_UDP_Channel import *
import Sim_Qpack_KC390

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
    msg_struct = {'': 'T_LCU_Status_Request_Message'}
    DATA_CHANNEL.Send_Tx(Sim_Qpack_KC390.Pack_Message(msg_struct))
# ------------------------------------------------------------------------------
def Send_T_LCU_BIT_Request():
    msg_struct = {'': 'T_LCU_BIT_Request_Message',
            'Lock_1_Actuator_Serial_Switch_IBIT':   '',
            'Lock_2_Actuator_Serial_Switch_IBIT':   '',
            'Lock_1_Actuator_Serial_Switch_State':  '',
            'Lock_2_Actuator_Serial_Switch_State':  '',
            'Lock_1_Solenoid_Serial_Switch_IBIT':   '',
            'Lock_2_Solenoid_Serial_Switch_IBIT':   '',
            'Lock_1_Solenoid_Serial_Switch_State':  '',
            'Lock_2_Solenoid_Serial_Switch_State':  '',
            }
    DATA_CHANNEL.Send_Tx(Sim_Qpack_KC390.Pack_Message(msg_struct))
# ------------------------------------------------------------------------------
def Send_T_LCU_Set_Lock_State_Command_Message(lock_1_state, lock_2_state):

    # JWL: TODO Is there a design issue/opportunity here?
# TODO any given LCU will only care about a pair of lock states, and furthermore
# TODO any given CP can only control a pair as well.
# TODO My guess is that the Dest_ID controls how the message is used, but
# TODO this still represents quite a bit of mis-information floating around.
# TODO why not 'UINT16 Lock_A_Id; UINT16 Lock_A_State; UINT16 Lock_B_Id; UINT16 Lock_B_State'
# TODO or even notice BIT Req just calls them 'Lock_1/Lock_2' so no need for '_Id'
    msg_struct = {'': 'T_LCU_Set_Lock_State_Command_Message',
            'Lock_1_State': lock_1_state,
            'Lock_2_State': lock_2_state,
            }
    DATA_CHANNEL.Send_Tx(Sim_Qpack_KC390.Pack_Message(msg_struct))
# ------------------------------------------------------------------------------
def Send_T_LCU_Force_Request_Message():
    msg_struct = {'': 'T_LCU_Force_Request_Message'}
    DATA_CHANNEL.Send_Tx(Sim_Qpack_KC390.Pack_Message(msg_struct))

# ==============================================================================
# RX
# ==============================================================================
def Recv_T_LCU_Status_Response_Message(msg_struct):
    # UINT8                BIT_Passed;
    # UINT16               Lock_Sensor_Count;
    # T_Lock_Sensor_Data  * Lock_Sensor_Data;
    #     typedef struct {
    #         UINT8                Lock_Busy;
    #         UINT16               Lock_State;
    #         UINT16               Next_Lock_State;
    #     } T_Lock_Sensor_Data;
    print msg_struct['']
    CP_SIM.set_state('AFT',   'UNLOCKED')
    CP_SIM.set_state('FWD',   'UNLOCKED')
    CP_SIM.set_state('CRG_L', 'UNLOCKED')
    CP_SIM.set_state('CRG_R', 'UNLOCKED')
# ------------------------------------------------------------------------------
def Recv_T_LCU_BIT_Response_Message(msg_struct):
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
    print msg_struct['']
# ------------------------------------------------------------------------------
def Recv_T_LCU_Force_Response_Message(msg_struct):
    # Lock_1_Dog_Displacement_Force_Sensor;
    # Lock_2_Dog_Displacement_Force_Sensor;
    print msg_struct['']
# ------------------------------------------------------------------------------
def Recv_Message(msg):
    msg_struct = Sim_Qpack_KC390.Unpack_Message(msg)
    msg_type   = msg_struct['']

    if msg_type == 'T_LCU_Status_Response_Message':
        # TODO Inc_Var('RESP_STAT.count')
        Recv_T_LCU_Status_Response_Message(msg_struct)

    elif msg_type == 'T_LCU_BIT_Response_Message':
        # TODO Inc_Var('RESP_BIT.count')
        Recv_T_LCU_BIT_Response_Message(msg_struct)

    elif msg_type == 'T_LCU_Force_Response_Message':
        # TODO Inc_Var('RESP_FORCE.count')
        Recv_T_LCU_Force_Response_Message(msg_struct)

    else:
        print 'Recv_Message - unknown - ' + msg

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
# TODO - kludge should be handled by parent, not button itself
                Send_T_LCU_Set_Lock_State_Command_Message(self.state, self.state)
            elif self.state == 'REQ_STAT':
                Send_T_LCU_Status_Request_Message()
            elif self.state == 'REQ_BIT':
                Send_T_LCU_BIT_Request()
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
        self.parent             = parent
        self.grid_row           = 0
        self.testing            = False
        self.first_lock_id      = first_lock_id
        self.add_label_button(-1,              'REQ_STAT',  'REQ_STAT')
        self.add_label_button(-1,              'REQ_BIT',   'REQ_BIT')
        self.add_label_button(-1,              'REQ_FORCE', 'REQ_FORCE')
        self.add_label_button(first_lock_id,   'TEST',      'NO_TEST')
        self.add_label_button(first_lock_id+1, 'AFT',       'ARMED')
        self.add_label_button(first_lock_id,   'FWD',       'ARMED')
        if lcp_type == 1:
            self.add_label_button(first_lock_id+1, 'CRG_L', 'ARMED')
            self.add_label_button(first_lock_id,   'CRG_R', 'ARMED')
        elif lcp_type == 2:
            pass   # There are no more buttons for Type 2
      # elif lcp_type == 3:  TODO perhaps RCP should be considered Type 3 ?

        self.btn['TEST'].set_click_handler(self.click_test)
# ------------------------------------------------------------------------------
    def add_label_button(self, lock_id, label, state):
        self.lbl[label] = CP_Label  (self.parent,  self.grid_row, lock_id, label)
        self.btn[label] = CP_Button (self.parent,  self.grid_row, lock_id, state)
        self.grid_row += 1
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
