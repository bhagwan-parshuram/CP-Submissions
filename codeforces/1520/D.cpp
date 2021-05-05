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

void solve(){
	ll n;
	cin>>n;
	ll a[n+1];
	map<ll,ll> mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]-i]++;
	}
	ll ans=0;
	for(auto u:mp){
		ll curr=u.second;
        ans+=(curr*(curr-1))/2;
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
