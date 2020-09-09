#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int >gr[N];

void dfsHelper(int src, map<int, bool>&visited) {
	visited[src] = true;
	cout << src << " ";
	for (auto child : gr[src]) {
		if (!visited[child]) {
			dfsHelper(child, visited);
		}
	}
}
void dfs(int src) {
	map<int, bool>visited;
	for (auto it : gr) {
		for (auto child : it) {
			visited[child] = false;
		}
	}
	dfsHelper(src, visited);

}
int main() {
	for (int i = 0; i < 8; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1);

}