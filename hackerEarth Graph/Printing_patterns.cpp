#include<bits/stdc++.h>

#define ll long long int

#define mod 1000000007

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()

{fast;

ll r,c,x,y,i,j;

cin>>r>>c>>x>>y;

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

cout<<max(abs(x-i),abs(y-j))<<" ";

 

}

cout<<'\n';

}

 

return 0;

}