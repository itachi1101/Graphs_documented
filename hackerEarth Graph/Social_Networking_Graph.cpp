#include<bits/stdc++.h>
using namespace std;
void bfs(int src, vector<int>gr[],map<int , vector<int>>&d) {
	map<int, int>visited;
	queue<int>q;
	map<int , int>dist;
	q.push(src);
	visited[src] = true;
	dist[src] = 0;
	while (!q.empty()) {
		int node = q.front();
		d[src].push_back(dist[node]);
		q.pop();
		for (auto nbr : gr[node]) {
			if (!visited[nbr]) {
				dist[nbr] = dist[node] + 1;
				q.push(nbr);
				visited[nbr] = true;

			}
		}
	}
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int>gr[10005];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    map<int ,vector<int>>dist;
    for(int i=0;i<n;i++){
        
        bfs(i,gr,dist);
    }
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++){
        int src,t;
        cin>>src>>t;
        int cnt=0;
        for(auto v:dist[src]){
           if(v==t)cnt++;
        }
        cout<<cnt<<endl;
     
       
    }


    return 0;
}