#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include<cstring>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<pll> vpll; 
 
#define endl '\n' 
#define fast std::ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
/*
 
 Important Observaitons:
 void dfs(int par, int u, int dpth) {
    //can use a variable ne for checking if its a leaf
    int ne = 0;
    for(int v : edges[u]) {
        if (v == par) continue;
        ne++;
        dfs(u, v, dpth+1);
    }
    
    if (ne == 0) {
        if (dpth&1) {
            num_odds++;
        } else {
            num_evens++;
        }
    }
}

2. try to think of parity whenever distingushin between even and odd
3.finfing the common parent--
   for ( int u = 1; u <= n; u++ )
        if ( !vis[u] && leaf( u ) )
        {
            vis[u] = 1;
            int f = G[u][0];
            for ( int v : G[f] )
                if ( v != u && leaf( v ) )
                {
                    ans --;
                    vis[v] = 1;
                }
        }
*/
int in[100005];
vvi g;
int par[100005];
int dist[100005];
void dfs(int nn,int pp){
	par[nn]=pp;
	if(pp!=0)dist[nn]=dist[pp]+1;
	for(auto u:g[nn]){
		if(u==pp)continue;
		dfs(u,nn);
	}
}
void solve(){
	int n;
	cin>>n;
	g.resize(n+1);
	par[1]=0;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
		in[a]++;
		in[b]++;
	}
	set<int> st;
	for(int i=1;i<=n;i++){
	 if(in[i]>1){
        dfs(i,0);
        break;
      }
	}
	for(int i=1;i<=n;i++){
		if(in[i]==1){
          st.insert(dist[i]&1);
		}
	}
	map<int,int> m;
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			m[par[i]]++;
		}
	}
	int ans=n-1;
	for(auto [u,v]:m){
		if(u==0)continue;
		if(v>1)ans-=(v-1);
	}
	int mini=1;
	if(st.size()>1)mini=3;
	cout<<mini<<" "<<ans<<endl;

}

int main(){
   fast;
   //clock_t begin = clock();
   ll tc=1;//cin>>tc;
   for(ll i=1;i<=tc;i++){
       //cout<<"Case #"<<i<<": ";
       solve();
   }
   //clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;

}
