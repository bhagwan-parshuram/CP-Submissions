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
vvl g;
ll a[200005];
ll n,m;
ll dfs(ll node,ll par,ll count){

    if(a[node]==1)count++;
    else count=0;
    
    if(count>m) return 0;
    if(g[node].size()==1 && g[node][0]==par)return 1;
    
    ll ans=0;
    for(auto n: g[node]){
        if(n!=par){
            ans+=dfs(n,node,count);
        }
    }
    return ans;
    
}
void solve(){
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    g.clear();
    g.resize(n+1);
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cout<<dfs(1,0,0)<<endl;
}

int main(){
    fast;
    int t=1;
    while(t--)
      solve();
}
