#include "IpV4.h"


IpV4::IpV4() {
}

IpV4::IpV4(const string ip) {
    if(this->isValid(ip)) {
        this->ip = ip;
    }
    else {
        throw string("Ip is invalid. Please insert correct ip and try again!");
    }
}

bool IpV4::isValid(string ipAddress) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ipAddress.c_str(), &(sa.sin_addr))!=0;
}

IpV4::IpV4(const IpV4& orig) {
}

IpV4::~IpV4() {
}

