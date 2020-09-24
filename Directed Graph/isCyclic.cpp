#include<bits/stdc++.h>
using namespace std;
vector<int>gr[100];

int cycle = 0;

void dfs(int src, set<int>s, vector<bool>&visited) {
    visited[src] = true;
    s.insert(src);
    for (auto child : gr[src]) {
        if (!visited[child]) {
            dfs(child, s, visited);

        }
        else if (visited[child] == true && s.find(child) != s.end()) {
            cycle = 1;
        }


    }
    s.erase(s.find(src));
    return ;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }
    vector<bool>visited;
    visited.assign(n, false);
    set<int>s;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, s, visited);
    }

    if (cycle == 1)cout << "cycle\n";
    else cout << "no cycle\n";
}