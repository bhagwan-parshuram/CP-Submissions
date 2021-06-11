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
#define mp make_pair
ll n;
ll a[100005];
vector<vector<int>> g;
ll depth[100005];
ll par[100005][20];
ll GCD[100005][20];
int gcd(int x,int y){
    int maxi,mini;
    maxi=max(x,y);
    mini=min(x,y);
    if(mini==0)
        return maxi;
    while(maxi%mini!=0){
        int r=maxi%mini;
        maxi=mini;
        mini=r;
    }
    return mini;
}
void dfs(ll nn,ll pp){
  par[nn][0]=pp;
  GCD[nn][0]=a[nn];
  for(ll j=1;j<20;j++){
    par[nn][j]=par[par[nn][j-1]][j-1];
    GCD[nn][j]=gcd(GCD[par[nn][j-1]][j-1],GCD[nn][j-1]);
  }
  for(auto u: g[nn]){
    if(u==pp)continue;
     depth[u]=depth[nn]+1;
     dfs(u,nn);
  }
}

ll query(ll u,ll v){
  if(depth[v]>depth[u])swap(u,v);

  ll deep=depth[u]-depth[v];

  ll ans=0;
  for(int j=19;j>=0;j--){
    if(deep&(1LL<<j)){
         ans=gcd(ans,GCD[u][j]);
         u=par[u][j];
       }
    }
  if(u==v){
    return gcd(ans,a[u]);
  }
  for(int j=19;j>=0;j--){
      if(par[u][j]!=par[v][j]){
        ans=gcd(ans,gcd(GCD[u][j],GCD[v][j]));
        u=par[u][j];
        v=par[v][j];
      }
    }
    return gcd(ans,gcd(a[par[u][0]],gcd(a[u],a[v])));;
}
   
void solve(){
  cin>>n;
  g.clear();
  g.resize(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  a[0]=0;
  for(int i=1;i<n;i++){
    ll a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  ll q;
  cin>>q;
  dfs(1,0);
  depth[1]=1;
  while(q--){
    ll u,v;
    cin>>u>>v;
    cout<<query(u,v)<<endl;;
  }

}

int main(){
  fast;
  int t=1;
  cin>>t;
  while(t--)
    solve();
}
