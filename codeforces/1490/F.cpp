#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i,n) for(auto i=0;i<n;i++)
#define Fo(i,k,n) for(auto i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) prllf("%d\n",x)
#define pl(x) prllf("%lld\n",x)
#define ps(s) prllf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define  endl "\n"
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;




//=============================================================================



vi g[10000];

void solve() {
  ll n;
  cin>>n;
 map<ll,ll> a;
  for(ll i=0;i<n;i++){
  	ll x; cin>>x;
  	a[x]++;
  }
  vi v,pf;
  v.pb(0);
  for(auto u: a){
  	v.pb(u.S);
  }
  sort(all(v));
  pf=v;
  for(ll i=0;i<pf.size();i++){
   pf[i]+=pf[i-1];
  }
  ll ans=1e9;

  n=v.size()-1;
  for(auto c:v){
    ll i1,i2;
    ll curr=0;
    i1=lower_bound(all(v),c)-v.begin();
    i2=upper_bound(all(v),c)-v.begin();
    if(i1>0)curr+=pf[i1-1]-pf[0];
    if(i2<=n)curr+=pf[n]-pf[i2-1]-((n-i2+1)*c);



    ans=min(ans,curr);

  }
  cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    ll t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}




//=============================================================================
void ipgraph(ll n, ll m){
ll i, u, v;
while(m--){
cin>>u>>v;
    u--, v--;
g[u].pb(v);
g[v].pb(u);
}
}

void dfs(ll u, ll par){
for(ll v:g[u]){
if (v == par) continue;
dfs(v, u);
}
}

