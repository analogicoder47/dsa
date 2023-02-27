#include <iostream>
#include "../include/broker_info.h"
#include "../include/session.h"
#include "yaml.h"

using namespace std;

namespace YAML {
	template<>
	struct convert<BrokerInfo> {
		static Node encode(const BrokerInfo &rhs) {
			Node node;
			node.push_back(rhs.get_ip() );
			node.push_back(rhs.get_port() );
			node.push_back(rhs.get_target_compid() );
			node.push_back(rhs.get_exp_seqno() );
			node.push_back(rhs.get_passwd() );

			return node;
		}

		static bool decode(const Node &node, BrokerInfo &rhs) {
			rhs.set_ip(node["bkr_ip"].as<string>() );
			rhs.set_port(node["bkr_port"].as<int>() );
			rhs.set_target_compid(node["target_compid"].as<string>() );
			rhs.set_exp_seqno(node["expected_seqno"].as<int>() );
			rhs.set_passwd(node["passwd"].as<int>() );

			return true;
		}
	};

	template<>
	struct convert<Session> {
		static Node encode(const Session &rhs) {
			Node node;
			node.push_back(rhs.get_svrip() );
			node.push_back(rhs.get_svrport() );
			node.push_back(rhs.get_backlog() );
			node.push_back(rhs.get_sndr_compid() );
			node.push_back(rhs.get_bkrlist() );
			
			return node;
		}

		static bool decode(const Node &node, Session &rhs) {
			rhs.set_svrip(node["svr_ip"].as<string>() );
			rhs.set_svrport(node["svr_port"].as<int>() );
			rhs.set_backlog(node["backlog"].as<int>() );
			rhs.set_sndr_compid(node["sndr_compid"].as<string>() );
			rhs.set_bkrlist(node["bkr_list"].as<vector<BrokerInfo>>() );

			return true;
		}
	};
}

int main(int argc, const char** argv)
{
	string current_path{argv[1]};
	string yaml_conf_path = current_path + "/sessions.yaml";

	YAML::Node config = YAML::LoadFile(yaml_conf_path);
	if (config["sessions"]) {
		cout << "session size: " << config["sesions"].size() << endl << endl;

		vector<Session> sessionlist = config["sessions"].as<vector<Session>>();

		for (vector<Session>::iterator session = sessionlist.begin(); session != sessionlist.end(); session++) {
			cout << "session server ip: "      << session->get_svrip()       << endl;
			cout << "session server port: "    << session->get_svrport()     << endl;
			cout << "session server backlog: " << session->get_backlog()     << endl;
			cout << "session server compID: "  << session->get_sndr_compid() << endl;

			vector<BrokerInfo> bkrlist = session->get_bkrlist();
			for (vector<BrokerInfo>::iterator broker = bkrlist.begin(); broker != bkrlist.end(); broker++) {
				cout << "   broker ip: "     << broker->get_ip()            << endl;
				cout << "   broker port: "   << broker->get_port()          << endl;
				cout << "   broker compID: " << broker->get_target_compid() << endl;
				cout << "   broker seqno: "  << broker->get_exp_seqno()     << endl;
				cout << "   broker passwd: " << broker->get_passwd()        << endl;

				cout << "\n" << endl;
			}
			cout << "***********************************" << endl;
		}
	}
	return 0;
}
