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
    return inet_pton(AF_INET, ipAddress.c_str(), &(this->sockAddr.sin_addr))!=0;
}

string IpV4::getIp() {
    return this->ip;
}

IpV4::IpV4(const IpV4& orig) {
}

IpV4::~IpV4() {
}

