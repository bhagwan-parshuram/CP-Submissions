#include<bits/stdc++.h>
using namespace std;

vector<int> color;
vector<vector<int>> g;
vector<vector<int>> rev;
vector<int> topo;
/*
 1. Get the topological Sort(Dont forget to reverse)
 2. now iterate through the topo vector and call another dfs and if not visited increase the component
*/

void dfs(int nn){
  color[nn]=1;
  for(auto u: g[nn]){
      if(!color[u]){
          dfs(u);
      }
  }
    topo.push_back(nn);
}
vector<int>comp;
void dfs1(int nn,int cmp){
    comp[nn]=cmp;
    color[nn]=1;
    for(auto u:rev[nn]){
        if(!color[u])dfs1(u,cmp);
    }
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
	color=vector<int>(n+1,0);
    topo.clear();
    int cmp=0;
    g.clear();
    rev.clear();
    g.resize(n);
    rev.resize(n);
    
    for(auto u: edges){
        g[u[0]].push_back(u[1]);
        rev[u[1]].push_back(u[0]);
    }
    for(int i=0;i<n;i++)if(!color[i])dfs(i);
    reverse(topo.begin(),topo.end());
	color=vector<int>(n+1,0);
    comp=vector<int>(n+1,-1);
    for(int i=0;i<n;i++)if(!color[topo[i]]){
        dfs1(topo[i],cmp);cmp++;
        
    }
    return cmp;
}
