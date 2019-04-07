#ifndef PING_H
#define PING_H

#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <iostream>

#define MAX_IPV4_PACKET_SIZE 65535  // Maximum size of IPV4 packet (bytes)
#define MAX_IPV4_HEADER_SIZE 60     // Maximum size of IPV4 header (bytes)

// Maximum size of the ICMP data
#define	MAX_ICMP_DATA_SIZE (MAX_IPV4_PACKET_SIZE - MAX_IPV4_HEADER_SIZE - ICMP_MINLEN)

#define SOCK_DOMAIN     AF_INET
#define SOCK_TYPE       SOCK_RAW
#define SOCK_PROTOCOL   IPPROTO_ICMP

using namespace std;

class Ping {
public:
    Ping();
    Ping(string);
    Ping(const Ping& orig);
    
    void startPinging();
    
    virtual ~Ping();
private:
    int sockFd = socket(SOCK_DOMAIN, SOCK_TYPE, SOCK_PROTOCOL);
    string ip;
    struct sockaddr_in sendTo;
    
    void initSendToSockAddr();
};

#endif /* PING_H */

