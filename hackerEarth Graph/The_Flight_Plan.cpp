#include <bits/stdc++.h>
 
using namespace std;
 
 
 
 
int main(){
 
    int n,m,t,c;
 
    cin>>n>>m>>t>>c;
 
    vector<int> v[n+1];
 
    bool visited[n+1];
 
    memset(visited,0,sizeof(visited));
 
    for(int i=0;i<m;i++){
 
        int a,b;
 
        cin>>a>>b;
 
        v[a].push_back(b);
 
        v[b].push_back(a);
 
    }
 
    for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
 
    int parent[n+1];
 
    int a,b;
 
    cin>>a>>b;
 
    parent[a]=0;
 
    queue<int> q;
 
    q.push(a);
 
    visited[a]=true;
 
    bool ans=false;
 
    while(!q.empty()){
 
        int r=q.front();
 
        if(ans)break;
 
        q.pop();
 
        for(int i=0;i<(int)v[r].size();i++){
 
            if(!visited[v[r][i]]){
 
                parent[v[r][i]]=r;
 
                visited[v[r][i]]=true;
 
                if(v[r][i]==b){ans=true;break;}
 
                q.push(v[r][i]);
 
            }
 
        }
 
    }
 
    stack<int> temp;
 
    while(parent[b]!=0){
 
        temp.push(b);
 
        b=parent[b];
 
    }
 
    temp.push(a);
 
    cout<<temp.size()<<endl;
 
    while(!temp.empty()){
 
        cout<<temp.top()<<" ";
 
        temp.pop();
 
    }
 
}