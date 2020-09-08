#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int >gr[N];
void bfs(int src) {
	map<int, bool>visited;
	queue<int>q;
	q.push(src);
	visited[src] = true;
	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (auto nbr : gr[node]) {
			if (!visited[nbr]) {
				q.push(nbr);
				visited[nbr] = true;
			}
		}
	}
	return ;
}
int main() {
	for (int i = 0; i < 7; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	bfs(1);

}