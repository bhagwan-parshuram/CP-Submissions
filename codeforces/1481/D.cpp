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
vi visited;
void dfs(int node,vector<vector<char>> &g,vi cmp){
	visited[node]=1;

	for(auto neigh: g[node]){
		if(!visited[neigh]){
			cmp[neigh]=cmp[node];
			dfs(neigh,g,cmp);
		}
	}
}

void solve() {
  int i, j, n, m;
  cin>>n>>m;


 int key=0;

  vector<vector<char>> v(n);
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		char c;
  		cin>>c;
  		v[i].pb(c);
  	}
  }

  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		if(i==j)continue;

  		if(v[i][j]==v[j][i]){
  			cout<<"YES"<<endl;
  			cout<<i+1<<" ";
  			int k=1;
  			while(m--){
  				if(k&1)cout<<j+1<<" ";
  				else cout<<i+1<<" ";
  				k=(k+1)%2;
  			}
  			cout<<endl;
  			return;
  		}
  	}
  }

  if(m&1){
  	cout<<"YES"<<endl;
  	cout<<1<<" ";
  	while(m>0){
  		cout<<2<<" ";
  		m--;
  		if(m>0){
  			cout<<1<<" ";
  			m--;
  		}
  	}
  	cout<<endl;
  	return;
  }
  int a=0;int b=1;int c=2;
  if(!(m&1)){
  	if(n==2){
  		cout<<"NO"<<endl;
  		return;
  	}
  	cout<<"YES"<<endl;
      while(v[a][b]!=v[b][c]){
          a=(a+1)%3;
          b=(b+1)%3;
          c=(c+1)%3;
      }
      m/=2;
      if(m&1){
      	cout<<a+1<<" ";
      	int k=1;
      	while(m--){
      		if(k&1){
      			cout<<b+1<<" "<<c+1<<" ";
      		}
      		else{
      			cout<<b+1<<" "<<a+1<<" ";
      		}
      		k=(k+1)%2;
      	}
      	cout<<endl;
      }
      else{
      	cout<<b+1<<" ";
      	int k=1;
      	while(m--){
           if(k&1){
           	cout<<c+1<<" "<<b+1<<" ";
           }
           else{
           	cout<<a+1<<" "<<b+1<<" ";
           }
           k=(k+1)%2;
      	}
      	cout<<endl;
      }
  }

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

