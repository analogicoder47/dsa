#include "../include/session.h"

using namespace std;

string Session::get_svrip() const {
    return svrip;
}

void Session::set_svrip(const string ip) {
    svrip = ip;
}

int Session::get_svrport() const {
    return svrport;
}

void Session::set_svrport(const int port) {
    svrport = port;
}

int Session::get_backlog() const {
    return backlog;
}

void Session::set_backlog(const int backlog) {
    this->backlog = backlog;
}

string Session::get_sndr_compid() const {
    return sndr_compid;
}

void Session::set_sndr_compid(const string compid) {
    sndr_compid = compid;
}

vector<BrokerInfo> Session::get_bkrlist() const {
    return bkrlist;
}

void Session::set_bkrlist(const vector<BrokerInfo> list) {
    bkrlist = list;
}
