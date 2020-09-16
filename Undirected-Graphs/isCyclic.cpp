#include<bits/stdc++.h>
using namespace std;
vector<bool>visited;
bool dfs(int src, int par, vector<bool>&visited, vector<int> g[]) {
    visited[src] = true;
    for (auto child : g[src]) {
        if (!visited[child]) {
            dfs(child, src, visited, g);
        }
        else if (visited[child] == true and child != par) {
            return true;
        }

    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{

    visited.assign(V, false);
    for (int i = 0; i < V; i++) {
        for (int child : g[i]) {
            if (!visited[child]) {
                bool check = dfs(child, -1, visited, g);
                if (check) {
                    return true;
                }


            }
        }
    }
    return false;


}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    int m, n;
    vector<int>adj[a];
    for (int i = 0; i < b; i++) {
        cin >> m >> n;
        adj[m].push_back(n);
        adj[n].push_back(m);

    }
    cout << isCyclic(adj, a);

    return 0;

}