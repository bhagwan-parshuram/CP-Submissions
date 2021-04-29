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
#define mod 100000000
#define endl '\n' 
#define fast std::ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
ll dp[101][101][11][2];
ll N1,N2,K1,K2;

ll fun(int n1,int n2,int k,int who){
	if(n1>=N1 && n2>=N2)return 1;

	ll &ans=dp[n1][n2][k][who];

	if(ans!=-1)return ans;
	ans=0;
	if(who==0){
		if(k<K1 && n1<N1)ans=(ans+fun(n1+1,n2,k+1,who))%mod;
		if(n2<N2)ans=(ans+fun(n1,n2+1,1,1))%mod;
	}
	else{
		if(k<K2 && n2<N2)ans=(ans+fun(n1,n2+1,k+1,who))%mod;
		if(n1<N1)ans=(ans+fun(n1+1,n2,1,0))%mod;
	}
	return ans;
}
void solve(){
   memset(dp,-1,sizeof(dp));
   cin>>N1>>N2>>K1>>K2;
   cout<<(fun(1,0,1,0)+fun(0,1,1,1))%mod<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
