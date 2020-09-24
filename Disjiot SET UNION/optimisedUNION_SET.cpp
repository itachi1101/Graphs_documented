#include<bits/stdc++.h>
using namespace std;
/// find for set///
int Find(int i, int parent[]) {
	if (parent[i] == -1)return i;
	return parent[i] = Find(parent[i]);
}


///union function//
void Union(int x, int y, int parent[], int rank[]) {
	int s1 = Find(x);
	int s2 = Find(y);
	if (s1 != s2)
	{
		if (rank[s1] < rank[s2]) {
			parent[s1] = s2;
			rank[s2] += rank[s1];
		}
		else {
			parent[s2] = s1;
			rank[s1] += rank[s2];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int *parent = new int [V];
	int *rank = new rank[V]

	/////////////////////set all the values of the rank to 1 intitially //////////////
	for (int i = 0; i < v; i++)
		rank[i] = 1;
	return 0;
}