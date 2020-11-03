/// first we choose node having indegree==0
///

#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
vector<int>res;
int in[100];
void kahn(int n) {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push_back(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		res.push_back(curr);
		q.pop();
		for (int node : g[curr]) {
			in [node]--;
			if (in[node] == 0) {
				q.push(node);
			}
		}
	}
}
int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		in[y]++;
	}
	kahn(n);
}