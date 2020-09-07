#include<bits/stdc++.h>
using namespace std;
class graph {
	map<int , list<int>>l;
public:
	void addEdge(int x, int  y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfsHelper(int src, map<int, bool>&visited) {
		visited[src] = true;
		cout << src << "-->";
		for (auto nbrs : l[src]) {
			if (!visited[nbrs]) {
				dfsHelper(nbrs, visited);
			}
		}
	}
	void dfs(int src) {
		map<int, bool>visited;
		for (auto p : l) {
			int node = p.first;
			visited[node] = false;
		}
		dfsHelper(src, visited);
		cout << "END";
	}
};
int main() {

	graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 7);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.dfs(1);
	return 0;

}