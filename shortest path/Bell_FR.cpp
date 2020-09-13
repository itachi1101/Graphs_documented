#include<bits/stdc++.h>
using namespace std;
vector<int>bellman_ford(int n, int src, vector<vector<int>>edges) {
	vector<int>dis(n + 1, INT_MAX);
	dis[src] = 0;
	//relax all the edges n-1 times
	for (int i = 0; i < n - 1; i++) {
		for (auto x : edges) {
			int from = x[0], to = x[1], weight = x[2];
			if (dis[from] != INT_MAX && dis[to] > dis[from] + weight) {
				dis[to] = dis[from] + weight;
			}
		}
	}
	for (auto x : edges) {
		int from = x[0], to = x[1], weight = x[2];
		if (dis[from] != INT_MAX && dis[to] > dis[from] + weight) {
			cout << "Negative weight cycle is detected";
			exit(0);
		}
	}
	return dis;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>>edges;
	for (int i = 0; i < m; i++) {
		int from, to , weight;
		cin >> from >> to >> weight;
		edges.push_back({from, to, weight});
	}
	vector<int>dis = bellman_ford(n, 1, edges);
	for (int i = 1; i <= n; i++) {
		cout << "distance from source to " << i << " is " << dis[i] << " \n";
	}


}