import sys
from scapy.all import *

PORT = 53
DNS_SERVER = '8.8.8.8'

def dns_req(address):
    dns_req = IP(dst=DNS_SERVER)/UDP(dport=PORT)/DNS(rd=1, qd=DNSQR(qname=address))
    answer = sr1(dns_req, verbose=0)
    print(answer[DNS].summary())



if __name__ == '__main__':
    dns_req(sys.argv[1])


import socket

def nslookup(host):
    try:
        print(socket.gethostbyname(host))
    except socket.error:
        print("Error: Unknown host")