#include "../include/broker_info.h"

using namespace std;

string BrokerInfo::getIP() const {
    return ip;
}

void BrokerInfo::setIP(const string ip) {
    this->ip = ip;
}

int BrokerInfo::getPort() const {
    return port;
}

void BrokerInfo::setPort(const int port) {
    this->port = port;
}

string BrokerInfo::getTargetCompID() const {
    return targetCompID;
}

void BrokerInfo::setTargetCompID(const string targetCompID) {
    this->targetCompID = targetCompID;
}

int BrokerInfo::getExpSeqno() const {
    return expectedSeqno;
}

void BrokerInfo::setExpSeqno(const int seqno) {
    this->expectedSeqno = seqno;
}

int BrokerInfo::getPasswd() const {
    return passwd;
}

void BrokerInfo::setPasswd(const int passwd) {
    this->passwd = passwd;
}
