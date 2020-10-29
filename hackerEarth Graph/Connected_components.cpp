#include<bits/stdc++.h>
using namespace std;
void Dfs(int src , vector<bool>&used, vector<int>gr[]) {
    used[src] = true;
    for (auto child : gr[src]) {
        if (!used[child]) {
            Dfs(child, used, gr);
        }
    }
}
int main() {

    int n, e;
    cin >> n >> e;
    vector<int>gr[10005];
    for (int i = 1; i <= e; i++) {
        int v, u;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int connected_component = 0;
    vector<bool>used(n);
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (!used[i]) {
            connected_component++;
            Dfs(i, used, gr);

        }
    }

    cout << connected_component;
    return 0;
}