#include<bits/stdc++.h>
using namespace std;
class graph {
	map<int, list<int>>l;
public:
	void addEdge(int x, int y ) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void bfs(int src) {
		map<int, int>dis;
		queue<int>q;
		q.push(src);
		for (auto node_pair : l) {
			int node = node_pair.first;
			dis[node] = INT_MAX;
		}

		dis[src] = 0;
		while (!q.empty()) {
			int first = q.front();
			q.pop();
			for (auto node : l[first]) {
				if (dis[node] == INT_MAX) {
					q.push(node);
					dis[node] = dis[first] + 1;

				}
			}
		}

		///// print the distance of src to every node
		for (auto node_pair : l) {
			int node = node_pair.first;
			int distacne = dis[node];
			cout << "node " << node << " is " << distacne << " from the source\n";
		}
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.bfs(0);
	return 0;
}