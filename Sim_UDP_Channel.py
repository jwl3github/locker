import socket
import struct
import threading
import time

# ##############################################################################
class Sim_UDP_Channel():
    tx_group     = None
    tx_port      = None
    tx_sock      = None

    rx_group     = None
    rx_port      = None
    rx_sock      = None
    rx_handler   = None
    rx_thread    = None
    rx_thread_on = False
# ------------------------------------------------------------------------------
    def __init__(self, tx_group, tx_port, rx_group, rx_port):
        self.tx_group = tx_group
        self.tx_port  = tx_port
        self.rx_group = rx_group
        self.rx_port  = rx_port
# ==============================================================================
# Tx
# ==============================================================================
    def Start_Tx(self):
        while self.tx_sock is None:
            try:
                self.tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
                tx_ttl  = struct.pack('b', 2)
                self.tx_sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, tx_ttl)
            except:
                pass
# ------------------------------------------------------------------------------
    def Stop_Tx(self):
        if self.tx_sock is not None:
            self.tx_sock = None   # TODO fix this
# ------------------------------------------------------------------------------
    def Send_Tx(self, msg):
        if self.tx_sock is None:
            self.Start_Tx()
        self.tx_sock.sendto(msg, (self.tx_group, self.tx_port))
# ==============================================================================
# Rx
# ==============================================================================
    def Start_Rx(self, rx_handler):
        ''' Initialize the Rx socket and listener thread; all messages will be returned via rx_handler(msg). '''
        self.rx_handler = rx_handler
        while self.rx_sock is None:
            try:
                self.rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
                self.rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                self.rx_sock.bind(('', self.rx_port))
                mreq = struct.pack("4sl", socket.inet_aton(self.rx_group), socket.INADDR_ANY)
                self.rx_sock.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)
                break
            except:
                pass
        if not self.rx_thread_on:
            self.rx_thread_on = True
            self.rx_thread    = threading.Thread(target = self.Listen_Rx)
            self.rx_thread.start()
# ------------------------------------------------------------------------------
    def Stop_Rx(self):
        self.rx_handler = None
        self.rx_thread_started = False
        while self.rx_thread is not None:
            time.sleep(0.2)
        if self.rx_sock is not None:
            self.rx_sock = None   # TODO fix this
# ------------------------------------------------------------------------------
    def Listen_Rx(self):
        while self.rx_thread_on:
            # TODO add timeout so that rx_thread_on can control threading better
            msg = self.rx_sock.recv(10240)
            if msg:
                self.rx_handler(msg)
        self.rx_thread.quit()
        self.rx_thread = None
