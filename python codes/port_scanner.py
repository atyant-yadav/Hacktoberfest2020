#!/bin/python3

import sys
import socket
from datetime import datetime 


#define our target

if len(sys.argv) == 2:
	target = socket.gethostbyname(sys.argv[1]) # translate hostname to ipv4
else :
	print("invalid amount of args")
	print("syntax: python3 scanner.py <ip>")
	
#add banner

print ("-" * 50)
print("scanning target" +target)
print("time started: " +str(datetime.now()))
print ("-" * 50)
open_ports=[]
try : 
	for port in range(50,1200):
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		socket.setdefaulttimeout(1)
		result = s.connect_ex((target,port)) #returns an error indicator
		print("testing port {} " .format(port))
		if result == 0 :
			print("port {} is open".format(port))
			open_ports.append(port)
		s.close()
		
except KeyboardInterrupt:
	print("\nExiting program")
	sys.exit()

except socket.gaierror:
	print("hostname could not be resolved.")
	sys.exit()

except socket.error:
	print("couldnt connect")
	sys.exit()
	
print("the open ports are {}" .format(open_ports))
	