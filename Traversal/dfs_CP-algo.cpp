// this is the most simple implementation of DFS


// useful to compute the entry and exit times and vertex color



vector<vector<int>>adj;
int n;
vector<bool>visited;
void DFS(int v) {
	visited[v] = true;
	for (int child : adj[v]) {

		if (!visited[child])
			DFS(child);
	}
}


/////////color_ implementation////////////
vectro<int>time_in, time_out;
int dfs_timer = 0;
void dfs(int v) {
	time_in[v] = dfs_timer++;
	color[v] = 1;
	for (int u : adj[v])
		if (color[u] == 0)
			dfs(u);

	color[v] = 2;
	time_out[v] = dfs_timer++;

}