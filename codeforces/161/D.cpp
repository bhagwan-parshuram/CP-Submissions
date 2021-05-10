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
ll dp[100005][505];
ll ans;
void dfs(ll nn,ll pp){
    dp[nn][0]=1;
    for(auto u:g[nn]){
        if(u==pp)continue;

        dfs(u,nn);
        for(int i=0;i<K;i++)ans+=dp[nn][i]*dp[u][K-i-1];
        //ans+=dp[nn][K];
        for(int i=0;i<K;i++)dp[nn][i+1]+=dp[u][i];
    }
}

void solve(){
    cin>>n>>K;
    g.resize(n+1);
    ans=0;
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    while(t--)
      solve();
}


