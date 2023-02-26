#include "../include/session.h"

using namespace std;

string Session::getSvrIP() const {
    return svrIP;
}

void Session::setSvrIP(const string ip) {
    svrIP = ip;
}

int Session::getSvrPort() const {
    return svrPort;
}

void Session::setSvrPort(const int port) {
    svrPort = port;
}

int Session::getBacklog() const {
    return backlog;
}

void Session::setBacklog(const int backlog) {
    this->backlog = backlog;
}

string Session::getSndrCompID() const {
    return sndrCompID;
}

void Session::setSndrCompID(const string compID) {
    sndrCompID = compID;
}

vector<BrokerInfo> Session::getBrokerList() const {
    return brokerList;
}

void Session::setBrokerList(const vector<BrokerInfo> list) {
    brokerList = list;
}
