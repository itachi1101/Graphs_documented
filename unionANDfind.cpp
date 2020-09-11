#include<bits/stdc++.h>
using namespace std;
/// find for set///
int Find(int i, int parent[]) {
	if (parent[i] == -1)return i;
	return Find(parent[i]);
}


///union function//
void Union(int x, int y, int parent[]) {
	int s1 = Find(x);
	int s2 = Find(y);
	if (s1 != s2)
		parent[s2] = s1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int *parent = new int [V];
	return 0;
}