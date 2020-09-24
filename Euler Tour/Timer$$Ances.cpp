#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100005;
std::vector<int> gr[N];
int t_in[N], t_out[N], timer;
void euler_tour3(int cur, int par) {
  t_in[cur] = ++timer;
  for (auto x : gr[cur]) {
    if (x != par) {
      euler_tour3 (x, cur);
    }
  }

  t_out[cur] = timer;
  return ;
}
bool isAncestor(int x, int y) {
  return t_in[x] <= t_in[y] && t_out[x] >= t_out[y];
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    gr[x].pb(y);
    gr[y].pb(x);

  }
  timer = 0;
  euler_tour3(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << i << " " << t_in[i] << " " << t_out[i] << "\n";
  }
  if (isAncestor(1, 7)) {
    cout << "Yes";
  }
  else cout << "No";
  return 0;
}