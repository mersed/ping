#ifndef IPV4_H
#define IPV4_H

#include <iostream>
#include <arpa/inet.h>
#include <string>
#include <sstream>

using namespace std;

class IpV4 {
private:
    string ip;
    struct sockaddr_in sockAddr;
    
    bool isValid(string);
    
public:
    IpV4();
    IpV4(string ip);
    IpV4(const IpV4& orig);
    
    string getIp();
    
    virtual ~IpV4();

};

#endif /* IPV4_H */

