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
#define mod 1000000007
#define endl '\n' 
#define fast std::ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
ll mult(ll a,ll b){
	return (a*b)%mod;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	ll ans=1;
	while(k--){
      ans=mult(ans,n);
	}
	cout<<ans<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
