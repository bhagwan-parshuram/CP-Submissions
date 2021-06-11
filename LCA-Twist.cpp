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

template <typename T>
class tree{
public:
   vector<vector<T>> g;
   vector<vector<T>>par;
   vector<T> depth;
   ll log2n;
   //vector<vector<ll>> any;

   tree(T n){
    g.clear();
    par.clear();
    g.resize(n+1);
    log2n=(log2(n)+1);
    depth=vector<T>(n+1,0);
    par=vector<vector<T>>(n+1,vector<T>(log2n+1,0));
   }

   void addE(T a,T b){
    g[a].pb(b);
    g[b].pb(a);
   }
   void dfs(T nn,T pp){
    par[nn][0]=pp;
    for(ll i=1;i<=log2n;i++)par[nn][i]=par[par[nn][i-1]][i-1];
    for(auto u:g[nn]){
        if(u==pp)continue;
        depth[u]=depth[nn]+1;
        dfs(u,nn);
    }
   }
   T lca(T a,T b){
        if(depth[b]>depth[a])swap(a,b);
        T diff=depth[a]-depth[b];
        for(int i=log2n;i>=0;i--){
            if(diff&(1LL<<i))a=par[a][i];
        }
        if(a==b)return a;

        for(int i=log2n;i>=0;i--){
            if(par[a][i]!=par[b][i]){
                a=par[a][i];
                b=par[b][i];
            }
        }
        return par[a][0];
   }
};
void solve(){
    ll n;
    cin>>n;
    tree<ll> g(n);
    for(int i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        g.addE(a,b);
    }
    g.dfs(1,0);
    ll q;
    cin>>q;
    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;
        ll a=g.lca(x,z);
        ll b=g.lca(y,z);
        if(a==b){
            cout<<g.lca(x,y)<<endl;
        }else if(g.depth[a]<=g.depth[b]){
            cout<<b<<endl;
        }else cout<<a<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--)
      solve();
}
