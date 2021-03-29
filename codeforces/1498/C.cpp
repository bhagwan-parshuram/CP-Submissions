#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
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
int K,N;
ll dp[1001][1001];
ll fun(int n,int k){
    if(k==1)return 1;
    if(n==0)return 1;
    
    ll &ans=dp[n][k];
    if(ans!=-1)return ans;
    ans=((fun(n-1,k)%mod)+(fun(N-n,k-1)%mod))%mod;
	return ans;
}
void solve(){
	int n;
	cin>>N>>K;
	n=N;
	memset(dp,-1,sizeof(dp));
	int k=K;
	cout<<fun(n,k)<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
