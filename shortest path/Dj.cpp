#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph {
	unordered_map<T, list<pair<T, int>>>m;
public:
	void addEdge(T u, T v , int dist, bool bidr = true) {
		m[u].push_back(make_pair(v, dist));
		if (bidr) {
			m[v].push_back(make_pair(u, dist));
		}

	}
	void printList() {
		//iterate over all the key valuse pairs in the map
		for (auto j : m) {
			//refering to the cities
			cout << j.first << " -> ";
			//now over the cities
			for (auto l : j.second) {
				cout << "( " << l.first << "," << l.second << " )";
			}
			cout << "\n";
		}

	}
	void Dijsktra(T src) {
		// we hoave to maintain a distance map
		unordered_map<T, int>dis;
		for (auto j : m) {
			dis[j.first] = INT_MAX;

		}
		//by default set sorts according to the first value
		set<pair<int, T>>s;
		dis[src] = 0;
		s.insert(make_pair(0, src));
		while (!s.empty()) {
			//find the pair at front
			auto p = *(s.begin());
			T node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());

			// iterater over nbrs of the curent node
			for (auto childPair : m[node]) {
				if (nodeDist + childPair.second < dis[childPair.first]) {
					T dest = childPair.first;
					auto f = s.find(make_pair(dis[dest], dest));
					if (f != s.end()) {
						s.erase(f);
					}
					dis[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dis[dest], dest));
				}
			}
		}
		for (auto d : dis) {
			cout << d.first << " is located at dist of " << d.second << "\n";
		}

	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	graph<int>g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g. addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.Dijsktra(1);
	return 0;
}