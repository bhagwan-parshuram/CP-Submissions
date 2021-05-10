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

ll n,K;
vvi g;
ll indp[50005][505];
ll outdp[50005][505];
void dfs1(ll nn,ll pp){
    indp[nn][0]=1;
    for(auto u:g[nn]){
        if(u==pp)continue;
        dfs1(u,nn);
        for(int i=1;i<=K;i++){
            indp[nn][i]+=indp[u][i-1];
        } 
    }
}
void dfs2(int nn,int pp){
     if(pp!=0){
      for(int i=1;i<=K;i++)outdp[nn][i]+=outdp[pp][i-1]+indp[pp][i-1]-((i>=2)?indp[nn][i-2]:0);
     }
   for(auto u:g[nn]){
    if(u==pp)continue;
     dfs2(u,nn);
   }
}
void solve(){
    cin>>n>>K;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    ll ans=0;
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)ans+=(indp[i][K]+(outdp[i][K]));
    cout<<ans/2<<endl;
}

int main(){
    fast;
    int t=1;
    while(t--)
      solve();
}


