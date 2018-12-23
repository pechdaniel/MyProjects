from _thread import *

import socket
import struct

def common(a1,a2):
        l=[]
        for i in a1:
                for j in a2:
                        if i==j:
                                l.append(i)
                                break
        return l

mySocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mySocket.bind(('127.0.0.1', 1234))
mySocket.listen(10)

def clientthread(conn):
    a1 = []
    a2 = []
    while True:
        data = conn.recv(2)
        data = struct.unpack('!H', data)
        l1 = data[0]
        for i in range(l1):
            data = conn.recv(2)
            data = struct.unpack('!H', data)
            a1.append(data[0])
        data = conn.recv(2)
        data = struct.unpack('!H', data)
        l2 = data[0]
        for i in range(l2):
            data = conn.recv(2)
            data = struct.unpack('!H', data)
            a2.append(data[0])
        a3 = common(a1, a2)
        print('Data recieved and transfered back!')
        conn.send(struct.pack('!H', len(a3)))
        for i in a3:
            conn.send(struct.pack('!H', i))
    conn.close()

while 1:
    conn, addr = mySocket.accept()

    start_new_thread(clientthread, (conn,))

mySocket.close()