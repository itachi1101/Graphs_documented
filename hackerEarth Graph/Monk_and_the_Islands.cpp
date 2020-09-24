#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
int bfs(int src,int dest,vector<int>gr[]){
     map<int,int>dist;
     queue<int> q;
     q.push(src);
     dist[src]=0;
     visited[src]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto child:gr[front]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
                dist[child]=dist[front]+1;
            }
        }
    }
    return dist[dest];

}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int n,m;
        cin>>n>>m;
        vector<int>gr[100005];
        visited.assign(n,false);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
 
       int ans= bfs(1,n,gr);
        cout<<ans<<endl;
       
    }
    return 0;
}