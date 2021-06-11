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

vector<vector<ll>> g;
int visited[100005];
vector<ll> d1,d2;

void resetV(int n){
	for(int i=0;i<=n;i++)visited[i]=0;
}
void resetall(int n){
	g.clear();
	g.resize(n+1);
	d1.clear();
	d2.clear();
	for(int i=0;i<=n;i++){
		d1.pb(1e10);
		d2.pb(1e10);
	}
	resetV(n);
}
void bfs(int nn,vector<ll> &d){
	d[nn]=0;
	queue<int> q;
	q.push(nn);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
// d1[node]+d2[node]=distance between s and t
void solve(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	resetall(n);
  
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(s,d1);
	bfs(t,d2);
	// debug(s,t,d1[t],d2[s]);

	if(d1[t]>=1e9-1){
		cout<<-1<<endl;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			// debug(d1[i],d2[i],d1[t],i,t);
			if(d1[i]+d2[i]==d1[t])ans++;
		}
		cout<<ans<<endl;
	}
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
