#include <string>
#include <vector>
#include "broker_info.h"

#ifndef _SESSION_H__
#define _SESSION_H__

using namespace std;

class Session {
public:
    string getSvrIP() const;
    void   setSvrIP(const string);

    int    getSvrPort() const;
    void   setSvrPort(const int);

    int    getBacklog() const;
    void   setBacklog(const int);

    string getSndrCompID() const;
    void   setSndrCompID(const string);

    vector<BrokerInfo> getBrokerList() const;
    void               setBrokerList(const vector<BrokerInfo>);

private:
    string             svrIP;
    int                svrPort;
    int                backlog;
    string             sndrCompID;    
    vector<BrokerInfo> brokerList;
};

#endif
