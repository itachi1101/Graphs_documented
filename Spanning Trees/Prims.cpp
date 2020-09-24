#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100005;
class graph {
  //adjacency list
  vector<pair<int, int>>*l;
  int v;
public:
  graph(int v) {
    this ->v = v;
    l = new vector<pair<int, int>>[v];
  }
  void addEdge(int x, int y, int w) {
    l[x].pb({y, w});
    l[y].pb({x, w});
  }
  int prim_mst() {
    priority_queue < pair<int, int>, std::vector<pair<int, int>> greater<pair<int, int>>q;


    //visited array that denotes whether a node has been inclued MST or NOt
    bool *vis = new bool[v] {0};
    int ans = 0;
    //begin
    q.push({0, 0}); //weight,node
    while (!q.empty()) {
      //pick out the edge with minimum weight
      auto best = q.top();
      q.pop();
      int to = best.second;
      int weight = best.first;
      if (vis[to]) {
        // discard the edge and continue
        continue;
      }
      ans += weight;
      vis[to] = 1;
      //add the new edges in the queue
      for (auto x : l[to]) {
        if (vis[x.first] == 0) {
          q.push({x.second, x.first});
        }
      }
    }
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  return 0;
}