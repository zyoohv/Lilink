#! /usr/bin/python
import SocketServer 
import MySQLdb

class MyTCPHandler(SocketServer.BaseRequestHandler):
    def handle(self):
        self.data = self.request.recv(10240).strip()
        print 'receive data :', self.data
        db = MySQLdb.connect("localhost", "root", "Zyh@508061", "lilink_usr")
        cursor = db.cursor()
        cursor.execute(self.data)
        sendmsg = str(cursor.fetchall())
        self.request.sendall(sendmsg)
        print 'send message :', sendmsg

if __name__ == '__main__':
    HOST, PORT = '10.104.85.250', 50005

    server = SocketServer.TCPServer((HOST, PORT), MyTCPHandler)

    server.serve_forever()
