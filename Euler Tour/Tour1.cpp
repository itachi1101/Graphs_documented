#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100005;
std::vector<int> gr[N];
void euler_tour1(int cur, int par) {
  cout << cur << " ";
  for (auto x : gr[cur]) {
    if (x != par) {
      euler_tour1(x, cur);
      cout << cur << " ";
    }
  }
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    gr[x].pb(y);
    gr[y].pb(x);

  }
  euler_tour1(1, 0);
  return 0;
}