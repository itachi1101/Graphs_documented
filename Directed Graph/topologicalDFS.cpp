#include<bits/stdc++.h>
using namespace std;
class graph {
	map<int, list<int>>l;
public:
	void addEdge(int x, int y) {
		// we only have the directional edge
		l[x].push_back(y);

	}
	void dfsHelper(int node, map<int, bool>&visited, list<int>&ordering) {
		visited[node] = true;
		for (auto nbr : l[node]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited, ordering);
			}
		}
		ordering.push_front(node);

	}
	void dfs() {
		map<int, bool>visited;
		list<int>ordering;
		for (auto p : l) {
			int node = p.first;
			visited[node] = false;
		}
		for (auto p : l) {
			int node = p.first;
			if (!visited[node]) {
				dfsHelper(node, visited, ordering);
			}
		}

	}
}