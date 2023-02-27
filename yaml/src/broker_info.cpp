#include "../include/broker_info.h"

using namespace std;

string BrokerInfo::get_ip() const {
    return ip;
}

void BrokerInfo::set_ip(const string ip) {
    this->ip = ip;
}

int BrokerInfo::get_port() const {
    return port;
}

void BrokerInfo::set_port(const int port) {
    this->port = port;
}

string BrokerInfo::get_target_compid() const {
	return target_compid;
}

void BrokerInfo::set_target_compid(const string target_compid) {
    this->target_compid = target_compid;
}

int BrokerInfo::get_exp_seqno() const {
    return exp_seqno;
}

void BrokerInfo::set_exp_seqno(const int seqno) {
    this->exp_seqno = seqno;
}

int BrokerInfo::get_passwd() const {
    return passwd;
}

void BrokerInfo::set_passwd(const int passwd) {
    this->passwd = passwd;
}
