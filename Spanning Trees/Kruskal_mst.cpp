#include<bits/stdc++.h>
using namespace std;
/// find for set///
class dsu {
	int*parent;
	int*rank;
public:
	dsu(int n ) {
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = -1;
		}
	}
	int Find(int i) {
		if (parent[i] == -1)return i;
		return parent[i] = Find(parent[i]);
	}

	///union function//

	void Unite(int x, int y) {
		int s1 = Find(x);
		int s2 = Find(y);
		if (s1 != s2)// belong to two different sets
		{

			//here we are doing union by rank
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


};
class graph {
	vector<vector<int>> edgelist;
	int v;
public:
	graph(int v) {
		this->v = v;
	}
	void addEdge(int x, int y, int w) {
		edgelist.push_back({w, x, y});
	}
	int Kruskal_mst() {
		//step 1 sorting based upon weight
		sort(edgelist.begin(), edgelist.end());
		dsu s(v);
		int ans = 0;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];


			//// take the edge in Mst if it does not form a cycle
			if (s.Find(x) != s.Find(y)) {
				s.Unite(x, y);
				ans += w;
			}
		}
		return ans;
	}

};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);
	cout << g.Kruskal_mst() << endl;
	return 0;
}