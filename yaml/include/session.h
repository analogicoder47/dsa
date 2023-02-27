#include <string>
#include <vector>
#include "broker_info.h"

#ifndef _SESSION_H__
#define _SESSION_H__

using namespace std;

class Session {
public:
    string get_svrip() const;
    void   set_svrip(const string);

    int    get_svrport() const;
    void   set_svrport(const int);

    int    get_backlog() const;
    void   set_backlog(const int);

    string get_sndr_compid() const;
    void   set_sndr_compid(const string);

    vector<BrokerInfo> get_bkrlist() const;
    void               set_bkrlist(const vector<BrokerInfo>);

private:
    string             svrip;
    int                svrport;
    int                backlog;
    string             sndr_compid; 
    vector<BrokerInfo> bkrlist;
};

#endif
