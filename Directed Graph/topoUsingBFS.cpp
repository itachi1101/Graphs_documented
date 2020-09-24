#include<bits/stdc++.h>
using namespace std;
class graph {
	int v;

	list<int>*l;
public:
	graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
	}
	void sort() {
		int *indegree = new int[v];
		for (int i = 0; i < v; i++) {
			indegree[i] = 0;
		}
		queue<int>q;
		for (int i = 0; i < v; i++) {
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}
		for (int i = 0; i < v; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

	}
}