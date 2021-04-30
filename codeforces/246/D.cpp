#include <bits/stdc++.h>
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

ll n,m;
vvi g;
set<int> s[100005];
bool visited[100005];
int color[100005];
void dfs(int node){
	visited[node]=1;
	for(auto u: g[node]){
		if(color[u]!=color[node])s[color[node]].insert(color[u]);
		if(!visited[u])dfs(u);
		// s[color[u]].insert(color[node]);
	}
}
void solve(){
	cin>>n>>m;
	g.clear();
	g.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>color[i]; 
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
	    g[b].pb(a);
	}
	
	
	for(int i=1;i<=n;i++){
		if(!visited[i])dfs(i);
	}
	int c=-1;
	int maxi=-1;
	for(int i=1;i<=n;i++){
		if(int(s[color[i]].size())>maxi){
			maxi=s[color[i]].size();
			c=color[i];
		}
		else if(int(s[color[i]].size())==maxi){
			if(c>color[i])c=color[i];
		}
	}
	cout<<c<<endl;

}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
