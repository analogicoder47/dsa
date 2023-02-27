#include <string>

#ifndef _BROKER_INFO_H__
#define _BROKER_INFO_H__

using namespace std;

class BrokerInfo {
public:
	string get_ip() const;
	void   set_ip(const string);

	int    get_port() const;
	void   set_port(const int);

	string get_target_compid() const;
	void   set_target_compid(const string);

	int    get_exp_seqno() const;
	void   set_exp_seqno(const int);

	int    get_passwd() const;
	void   set_passwd(const int);

private:
	string  ip;
	int     port;
	string  target_compid;
	int     exp_seqno;
	int     passwd;
};

#endif
