#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i,n) for(auto i=0;i<n;i++)
#define Fo(i,k,n) for(auto i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) 
{cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) 
{int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
uniform_int_distribution<int> uid(0,lim-1);
return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int MAX = 3e5;
ll binpow(ll b,ll p){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}
return ans;}
ll inv(int n){return(binpow(n,mod-2));}
ll ncr(int n,int m)
{ll fac[n+1];fac[0]=1;Fo(i,1,n+1)fac[i]=(i*fac[i-1])%mod;
return ((fac[n]*inv(fac[m])%mod)*inv(fac[n-m]))%mod;}



//=============================================================================



vi g[MAX];

void solve() {
  int n,m;
  cin>>n>>m;
  vi a,b,c;

  fo(i,n){
  	int x;
  	cin>>x;
  	a.pb(x);
  }
  fo(i,n){
  	int x;
  	cin>>x;
  	b.pb(x);
  }
  fo(i,m){
  	int x;
  	cin>>x;
  	c.pb(x);
  }

  vi temp=b;
  sort(all(temp));
  map<int,vi> mp;

  for(int i=0;i<n;i++){
  	if(a[i]!=b[i]){
  		mp[b[i]].pb(i);
  	}
  }
  int ind=-1;
  	if(binary_search(all(temp),c[m-1])){
  		ind=c[m-1];
  	}
 
  if(ind==-1){
  	cout<<"NO"<<endl;
  	return;

  }
  for(int i=n-1;i>=0;i--){
  	if(b[i]==ind){
  		ind=i;
  		break;
  	}
  }

  vi ans(m,-1);
  for(int i=m-1;i>=0;i--){
  	if(mp.count(c[i])){
  		ans[i]=(mp[c[i]].back())+1;
  		mp[c[i]].pop_back();
  		if(mp[c[i]].size()==0) mp.erase(c[i]);
  	}
  	else{
  		if(ans[m-1]!=-1){
  			ans[i]=ans[m-1];
  		}
  		else{
  			ans[i]=ind+1;
  		}
  	}
  }

  for(auto u:mp){
  	if(mp[u.F].size()>0){
     cout<<"NO"<<endl;
     return;
  	}
  }
  cout<<"YES"<<endl;
  for(int i=0;i<m;i++)cout<<ans[i]<<" ";
  	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}




//=============================================================================
void ipgraph(int n, int m){
int i, u, v;
while(m--){
cin>>u>>v;
    u--, v--;
g[u].pb(v);
g[v].pb(u);
}
}

void dfs(int u, int par){
for(int v:g[u]){
if (v == par) continue;
dfs(v, u);
}
}

