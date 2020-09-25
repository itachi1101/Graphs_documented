#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>gr[],int val,int key,int n){
   vector<bool>visited;
   map<int,int>dist;
    visited.assign(n,false);
    queue<int>q;
    dist[val]=0;
    visited[val]=true;
    q.push(val);
    long long prod=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        prod=prod*node;
        if(prod==key){
            cout<<dist[node];
            return;
        }
        for(auto nbr:gr[node]){
            if(!visited[nbr]){
                visited[nbr]=true;
                dist[nbr]=dist[node]+1;
                q.push(nbr);
            }
        }

    }

}
int main(){
    int n;
    cin>>n;
    int key;
    cin>>key;
    int val;
    cin>>val;
    vector<int>gr[10000];
    for(int i;i<n;i++){
        int data;
        cin>>data;
        gr[val].push_back(data);
        gr[data].push_back(val);
    }
    bfs(gr,val,key ,n);
    return 0;
}