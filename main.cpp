#include <iostream>
#include <string>
#include "IpV4.h"

using namespace std;

string getIpAddress(int argc, char** argv) {
    if(argc == 1) {
        throw string("Please provide target ip as a parameter");
    }
    
    return argv[1];
}

int main(int argc, char** argv) {
    try {
        string ip = getIpAddress(argc, argv);
        IpV4 ipv4(ip);
    }
    catch(string err) {
        cout << "[ERROR] " + err << endl;
        return 1;
    }
}

