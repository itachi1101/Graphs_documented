#include<bits/stdc++.h>
using namespace std;
vector<int>gr[100];
int vis[100];
bool odd_cycle = 0;
void dfs(int cur, int par , int col ) {
    vis[cur] = col;
    for (auto child : gr[cur]) {
        if (vis[child] == 0) {
            dfs(child, cur, 3 - col);
        }
        else if (child != par && col == vis[child]) {
            odd_cycle = 1;
        }

    }
    return ;
}
int main() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1, 0, 1);
    if (odd_cycle)cout << "not Bipartite\n";
    else cout << "Bipartite\n";
}