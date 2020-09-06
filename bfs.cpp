#include<iostream>
#include<list>
#include<map>
#include<stack>
#include<queue>
using namespace std;
class graph {
	map<int, list<int>>l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}

	void Bfs(int src) {
		map<int, int>visited;
		queue<int>q;

		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

};
int main() {

	graph g;
	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(6, 2);
	g.Bfs(1);
	return 0;

}