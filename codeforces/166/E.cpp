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
#define mod 1000000007
ll dp[4];
ll previ[4];
void solve(){
	ll n;
	cin>>n;
	
    memset(dp,0,sizeof(dp));
    previ[0]=1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			dp[j]=0;
			for(int k=0;k<4;k++){
				if(j!=k)dp[j]+=previ[k];
				if(dp[j]>=mod)dp[j]%=mod;
				//cout<<j<<" "<<dp[j]<<" "<<k<<" "<<previ[k]<<endl;
			}
		}
		for(int j=0;j<4;j++)previ[j]=dp[j];

	}
   
	cout<<dp[0]<<endl;
	
}

int main(){
	fast;
	int t=1;
	//cin>>t;
	while(t--)
	  solve();
}
