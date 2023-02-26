#include <string>

#ifndef _BROKER_INFO_H__
#define _BROKER_INFO_H__

using namespace std;

class BrokerInfo {
public:
	string getIP() const;
	void   setIP(const string);

	int    getPort() const;
	void   setPort(const int);

	string getTargetCompID() const;
	void   setTargetCompID(const string);

	int    getExpSeqno() const;
	void   setExpSeqno(const int);

	int    getPasswd() const;
	void   setPasswd(const int);

private:
	string  ip;
	int     port;
	string  targetCompID;
	int     expectedSeqno;
	int     passwd;
};

#endif
