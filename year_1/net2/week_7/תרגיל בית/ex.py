from scapy.all import *
from sqlalchemy import case
from scapy.layers.http import HTTPRequest # import HTTP packet
from colorama import init, Fore

IPforc = "34.218.16.79"

welcame = """Welcome to Magshishark!
Please select sniffing state:
1. DNS 
2. Forecast
3. HTTP
Or select 0 to Exit: """

def main():
    print(welcame)
    choice = input()
    if choice == "1":
        dns_sniff()
    elif choice == "2":
        forecast_sniff()
    elif choice == "3":
        http_sniff()
    elif choice == "0":
        print("Bye!")
        exit()
    else:
        print("Invalid choice!")
        main()
    return 0


def is_dns(packet):
    return DNS in packet

def dns_sniff():
    print("Sniffing DNS...")
    pacage = sniff(lfilter=is_dns, prn = print_dns_prn)
    print("Done!")

def print_dns_prn(packet):
    print(packet[DNS].summary())

def is_forecast(packet):
    return IP in packet and packet[IP].src == "34.218.16.79" and Raw in packet and '200:ANSWER' in packet[Raw].load.decode()
#def is_forecast(packet):
#    return (TCP in packet
#            and (packet[TCP].sport == 77
#                 or packet[TCP].dport == 77))


def forecast_sniff():
    print("Sniffing Forecast...")
    pacage = sniff(lfilter=is_forecast,prn=print_forecast_prn)
    print("Done!")


def print_forecast_prn(packet):
    print(packet[Raw].load.decode())


def is_http(packet):
        return packet.haslayer(HTTPRequest) and packet[HTTPRequest].Method==b'GET'


def http_sniff():
    print("Sniffing HTTP...")
    pacage = sniff(lfilter=is_http,prn=print_http_prn)
    print("Done!")


def print_http_prn(packet):
    if packet.haslayer(HTTPRequest):
        # if this packet is an HTTP Request
        # get the requested URL
        url = packet[HTTPRequest].Host.decode() + packet[HTTPRequest].Path.decode()

        print(url)
    else:
        print("Unknown HTTP")





def print_packet(packet):
    print (packet[IP].src, "-", packet[IP].dst) 



if __name__ == '__main__':
    main()