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
ll n,q;
ll a[1000005];
ll gtr[1000005];
vector<vector<ll>> g;
int dp[1000005][30];
ll log2n;
ll log(ll x){
    ll ans=log2(x)+1;
    return ans;
}
void nextG(){
    stack<ll> st;
    for(int i=0;i<=n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            gtr[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
}
void constructGraph(){
   g.resize(n+1);
   for(int i=0;i<n;i++){
    g[i].pb(gtr[i]);
    g[gtr[i]].pb(i);
   }
}
void dfs(int nn,int pp){
    dp[nn][0]=pp;
    for(int i=1;i<=log2n;i++)dp[nn][i]=dp[dp[nn][i-1]][i-1];
    for(auto u:g[nn]){
        if(u==pp)continue;
        dfs(u,nn);
    }
}
ll query(ll l,ll r){
   ll cnt=1;
   ll curr=l;
   for(int i=log2n;i>=0;i--){
    if(dp[curr][i]<=r){
        cnt+=(1LL<<i);
        curr=dp[curr][i];
    }
   }
   return cnt;
}
void reset(){
    g.clear();
}
void solve(){
    reset();
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    a[n]=1e15;
    log2n=log(n);
    nextG();
    constructGraph();
    dfs(n,n);

    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        if(r<l){
            cout<<0<<endl;
        }
        else cout<<query(l,r)<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--)
      solve();
}
