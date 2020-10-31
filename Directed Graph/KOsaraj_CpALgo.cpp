
vector<int>g[10000], grr[10000];
vector<bool>used;
vector<int>order , component;

void dfs1(int v) {
	used[v] = true;
	for (auto child : g[v]) {
		if (!used[child]) {
			dfs1(child);
		}
		order.push_back(v);
	}
}
void dfs2(int v) {

}


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		grr[b].push_back(a);
	}

	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (used[i] == false) {
			dfs1(i);
		}
	}
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			cout << "strongly connected component of are-->";
			dfs2(v);
			for
		}
}
}