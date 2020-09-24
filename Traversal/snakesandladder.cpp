#include<bits/stdc++.h>
using namespace std;

class graph {
	map<int, list<int>>l;
public:
	void addEdge(int x, int y ) {
		l[x].push_back(y);
	}
	int bsf(int src, int dest) {
		map<int, int >dist;
		map<int, int>parent;
		queue<int>q;
		for (auto node_pair : l) {
			int node = node_pair.first;
			dist[node] = INT_MAX;

		}
		q.push(src);
		dist[src] = 0;
		parent[src] = src;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}
		int temp = dest;
		while (temp != src) {
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << src << endl;
		return dist[dest];
	}


};






int main() {


	int board[10000];
	for (int i = 0; i <= 36; i++) {
		board[i] = 0;
	}

	board[2] =   13;
	board[5] =    2;
	board[9] =   18;
	board[18] =  11;
	board[17] = -13;
	board[20] = -14;
	board[24] =  -8;
	board[25] =  10;
	board[32] =  -2;
	board[34] = -22;

	graph g;
	for (int i = 0; i <= 36; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int j = i + dice;
			j += board[j];
			if (j <= 36) {
				g.addEdge(i, j);
			}
		}
	}
	g.addEdge(36, 36);

	cout << g.bsf(0, 36);
	return 0;

}


