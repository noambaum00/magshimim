from scapy.all import *
import sys

hostname = "142.251.37.238"







def tracert1(hostname):
    for i in range(1, 28):
        pkt = IP(dst=hostname, ttl=i) / UDP(dport=33434)
        # Send the packet and get a reply
        try:
            reply = sr1(pkt, timeout=1, verbose=0)
        except:
            print("Timeout waiting for %s" % pkt[IP].dst)
            break
        reply = sr1(pkt, verbose=0)

        if reply is None:
            # No reply :(
            break
        else:
            # We in the middle somewhere
            print("%d: " % i , reply.src)


if "__main__" == "__main__":
    tracert1(sys.argv[1])
