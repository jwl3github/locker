from Tkinter import *
import socket
import struct
import threading

mcast = [ {'grp':'224.1.1.1', 'port': 5006},
          {'grp':'224.1.1.2', 'port': 5007} ]

text_w = None
text_lock = threading.Lock()
listen_thread = []

# ------------------------------------------------------------------------------
def record_msg(text):
    text_lock.acquire()
    print text
    if text_w: text_w.insert(END, text + '\n')
    text_lock.release()

# ------------------------------------------------------------------------------
def Rx_UDP(mcast_info):
    rx_sock = None
    while True:
        try:
            rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
            rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            rx_sock.bind(('', mcast_info['port']))
            mreq = struct.pack("4sl", socket.inet_aton(mcast_info['grp']), socket.INADDR_ANY)
            rx_sock.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)
            break
        except:
            pass
    while True:
        #record_msg('Listening on %s:%d' % (mcast_info['grp'], mcast_info['port']))
        msg = rx_sock.recv(10240)
        record_msg('%s:%d - %s' % (mcast_info['grp'], mcast_info['port'], msg))
# ------------------------------------------------------------------------------
def Start_Rx_UDP_0():
    Rx_UDP(mcast[0])
# ------------------------------------------------------------------------------
def Start_Rx_UDP_1():
    Rx_UDP(mcast[1])

# ##############################################################################
listen_thread.append(threading.Thread(target = Start_Rx_UDP_0))
listen_thread[-1].start()

listen_thread.append(threading.Thread(target = Start_Rx_UDP_1))
listen_thread[-1].start()

tk_root  = Tk()

scroll_x = Scrollbar(tk_root, orient=HORIZONTAL)
scroll_x.pack(side=BOTTOM, fill=X)

scroll_y = Scrollbar(tk_root)
scroll_y.pack(side=RIGHT, fill=Y)

text_w = Text(tk_root, wrap=NONE,
              yscrollcommand=scroll_y.set,
              xscrollcommand=scroll_x.set)
text_w.pack()

scroll_x.config(command=text_w.xview)
scroll_y.config(command=text_w.yview)

tk_root.mainloop()
