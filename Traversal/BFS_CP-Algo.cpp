
void bfs(int src, int n) {
	queue<int>q;
	vector<bool>used(n);
	q.push(src);
	used[src] = true;
	while (!q.empty()) {
		int v = q.front();
		cout << v << " ";
		q.pop();
		for (int neighbour : adj[v]) {
			if (!used[neighbour]) {
				used[neighbour] = true;
				q.push(neighbour);
			}
		}
	}
}

