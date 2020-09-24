#include<iostream>
#include<list>
using namespace std;

class graph {
	int v;
	list<int>*l;
public:
	graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void print() {
		for (int i = 0; i < v; i++) {
			cout << "vertex is" << i << "->";

			for (int x : l[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
};






int main() {
	graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.print();
}