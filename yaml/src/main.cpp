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
			node.push_back(rhs.getIP() );
			node.push_back(rhs.getPort() );
			node.push_back(rhs.getTargetCompID() );
			node.push_back(rhs.getExpSeqno() );
			node.push_back(rhs.getPasswd() );

			return node;
		}

		static bool decode(const Node &node, BrokerInfo &rhs) {
			rhs.setIP(node["brkr_ip"].as<string>() );
			rhs.setPort(node["brkr_port"].as<int>() );
			rhs.setTargetCompID(node["target_comp_id"].as<string>() );
			rhs.setExpSeqno(node["expected_seqno"].as<int>() );
			rhs.setPasswd(node["passwd"].as<int>() );

			return true;
		}
	};

	template<>
	struct convert<Session> {
		static Node encode(const Session &rhs) {
			Node node;
			node.push_back(rhs.getSvrIP() );
			node.push_back(rhs.getSvrPort() );
			node.push_back(rhs.getBacklog() );
			node.push_back(rhs.getSndrCompID() );
			node.push_back(rhs.getBrokerList() );
			
			return node;
		}

		static bool decode(const Node &node, Session &rhs) {
			rhs.setSvrIP(node["svr_ip"].as<string>() );
			rhs.setSvrPort(node["svr_port"].as<int>() );
			rhs.setBacklog(node["backlog"].as<int>() );
			rhs.setSndrCompID(node["sndr_comp_id"].as<string>() );
			rhs.setBrokerList(node["brkr_list"].as<vector<BrokerInfo>>() );

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

		vector<Session> sessionList = config["sessions"].as<vector<Session>>();

		for (vector<Session>::iterator session = sessionList.begin(); session != sessionList.end(); session++) {
			cout << "session server ip: "      << session->getSvrIP()      << endl;
			cout << "session server port: "    << session->getSvrPort()    << endl;
			cout << "session server backlog: " << session->getBacklog()    << endl;
			cout << "session server compID: "  << session->getSndrCompID() << endl;

			vector<BrokerInfo> brokerList = session->getBrokerList();
			for (vector<BrokerInfo>::iterator broker = brokerList.begin(); broker != brokerList.end(); broker++) {
				cout << "   broker ip: "     << broker->getIP()            << endl;
				cout << "   broker port: "   << broker->getPort()          << endl;
				cout << "   broker compID: " << broker->getTargetCompID()  << endl;
				cout << "   broker seqno: "  << broker->getExpSeqno()      << endl;
				cout << "   broker passwd: " << broker->getPasswd()        << endl;

				cout << "\n" << endl;
			}
			cout << "***********************************" << endl;
		}
	}
	return 0;
}
