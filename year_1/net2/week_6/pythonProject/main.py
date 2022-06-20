from scapy import *
import admin

if not admin.isUserAdmin():
        admin.runAsAdmin()

answer = sr1(IP(dst="8.8.8.8")/UDP(dport=53)/DNS(rd=1,qd=DNSQR(qname="google.com")),verbose=0)

print(answer[DNS].summary())
