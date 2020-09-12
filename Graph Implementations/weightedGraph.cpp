#include<iostream>
#include<cstring>
#include<list>
#include<unordered_map>
using namespace std;

class graph {
	unordered_map<string, pair<string, int>>l;
public:
	void addEdge(string x, string y, bool dir, int wt) {
		l[x].push_back(y);
		if (dir) {
			l[y].push_back(x);
		}
	}
	void print() {
		for (auto pair : l) {
			string first = p.first;
			list<pair<string, int>>nbr = p.second;
			for (auto nbrs : nbr) {
				string dest = nbr.first;
				int dist = nbr.second;
				cout << dest << " " << dist << " ";
			}
			cout << endl;
		}
	}

};