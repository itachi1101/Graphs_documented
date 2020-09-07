#include<bits/stdc++.h>
using namespace std;
class graph {
	map<int, list<int>>l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}
	void dfsHelper(int src, map<int, bool>&visited) {
		visited[src] = true;
		cout << src << " ";
		for (auto nbrs : l[src]) {
			if (!visited[nbrs]) {
				dfsHelper(nbrs, visited);
			}
		}
	}
	void dfs() {
		map<int, bool>visited;
		for (auto p : l) {
			int node = p.first;
			visited[node] = false;
		}
		int cnt = 0;
		for (auto p : l) {
			int node = p.first;
			if (!visited[node]) {
				cout << "component " << cnt + 1 << "-->";
				dfsHelper(node, visited);
				cnt++;
				cout << endl;
			}
		}
	}
};
int main() {

	graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(8, 8);
	g.dfs();
	return 0;

}