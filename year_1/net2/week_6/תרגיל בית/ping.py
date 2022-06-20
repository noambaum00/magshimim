import datetime
from scapy.all import *
import sys

TIMEOUT = 5
TTL = 60
myIP = '127.0.0.1'
bit32 = '00100101001000000010000001100100'

def ping():
     print("Pinging " + str(myIP) + " with " + str(sys.getsizeof(bit32)) + " bytes of data:")
     for ip in range(4):
          packet = IP(dst=myIP + str(ip), ttl=TTL)/ICMP()
          time1 = datetime.now()
          reply = sr1(packet, timeout=TIMEOUT, verbose=0)
          time2 = datetime.now()
          timeAll = time1 - time2
          timeAll = timeAll.total_seconds()
          if not (reply is None):
               print("Reply from: " + reply.dst + " time=" + str(timeAll) + " TTL=" + str(TTL))
          else:
               print ("Timeout waiting for %s" % packet[IP].dst)


if "__name__" == "__main__":
    ping(sys.argv[1])