int n;
vector<int>g[MAXN];
bool used[MAXN];
vector<int>comp;
void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i < (int)g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}
void find_comps() {
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			cout << "connected:";
			for (size_t j = 0; j < comp.size(); ++j) {
				cout << " " << comp[j];

			} cout << endl;
		}
	}
}