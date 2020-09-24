#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>floyd_warshall(vector<vector<int>>graph) {
    vetor<vectro<int>>dist(graph);
    int v = graph.size();
    for (int i = 0; i < v; i++) {
        for (int j = i; i < v; j++) {
            for (int k = 0; k < v; k++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}