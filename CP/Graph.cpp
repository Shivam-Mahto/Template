#include<bits/stdc++.h>
using namespace std;
#define ll long long


void dfs(int src, vector<int> &vis,vector<int> adj[])
{
    vis[src] = 1;
    cout<<src<<" ";
    for(auto x: adj[src])
    {
        if(!vis[x])
            dfs(x,vis,adj);
    }
}


int main()
{
    int v,e;
    cin>>v>>e;

    vector<int> adj[v+1];
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    for(int i=1; i<=v; i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> vis(v+1,0);
    dfs(1,vis,adj);

    return 0;
}