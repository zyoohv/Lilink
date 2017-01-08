#! /usr/bin/python
import SocketServer 
import MySQLdb
import json

class MyTCPHandler(SocketServer.BaseRequestHandler):
	def handle(self):
		self.data = self.request.recv(10240).strip()
		print 'receive data :', self.data
		db = MySQLdb.connect("localhost", "root", "Zyh@508061", "lilink_usr")
		cursor = db.cursor()
		cursor.execute(self.data)
		db.commit()
		sendmsg = cursor.fetchall()
		db.close()
		print 'searching result:', sendmsg
		js = self.encodeToJson(sendmsg)
		self.request.sendall(str(js))
		print 'sending message :', js

	def encodeToJson(self, sendmsg):
		data = {}
		id = 0
		for msg in sendmsg:
			for nex in msg:
				if not nex: nex = ' '
				data[str(id)] = nex 
				id += 1
		return json.dumps(data, sort_keys=True)


if __name__ == '__main__':
	HOST, PORT = '10.104.85.250', 50005
	server = SocketServer.TCPServer((HOST, PORT), MyTCPHandler)
	server.serve_forever()
