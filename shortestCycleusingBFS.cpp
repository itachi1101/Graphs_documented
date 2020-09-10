#include<bits/stdc++.h>
using namespace std;


const int N = 100005;
vector<int>gr[N];
void bfs(int src, int  n, int& ans) {
	vector<int>distance(n + 1, INT_MAX);
	queue<int>q;
	q.push(src);
	distance[src] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nbr : gr[cur]) {
			if (distance[nbr] == INT_MAX) {
				//neighbour is not visited simple edge not a backedge
				distance[nbr] = distance[cur] + 1;
				q.push(nbr);
			}
			else if (distance[nbr] >= distance[cur]) {
				ans = min(ans, distance[nbr] + distance[cur] + 1);
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);

	}
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		bfs(i, n, ans);
	}
	if (ans == n + 1) {
		cout << "no cycle";
	}
	else {
		cout << "shortes cycle is of length " << ans;
	}
}