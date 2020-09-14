#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000], grr[1000];
vector<bool>used;
vector<int>order, component;

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
  used[v] = true;
  component.push_back(v);
  for (auto child : grr[v]) {
    if (!used[child]) {
      dfs2(child);
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    grr[b].push_back(a);
  }
  used.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (used[i] == false) {
      dfs1(i);
    }
  }
  used.assign(n, false);
  for (int i = 0; i < n; i++) {
    int v = order[n - 1 - i];

    if (!used[v]) {
      cout << "strongly connected component of are --> ";
      dfs2(v);
      for (auto it = component.begin(); it != component.end(); it++)cout << *(it) << " " ;
      component.clear(); cout << endl;
    }


  }
  return 0;
}