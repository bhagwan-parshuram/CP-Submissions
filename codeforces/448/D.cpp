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
ll m,n,k;
bool check(ll a){
	ll ans=0;
	for(int i=1;i<=n;i++){
       ans+=min(m,((a-1)/i));
	}
	return (ans<k);
}
void solve(){
	cin>>n>>m>>k;
	ll lo=0;
	ll hi=n*m;
	ll ans=n*m;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		if(check(mid)){
			ans=mid;
			lo=mid+1;
		}
		else hi=mid-1;
	}
	cout<<ans<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
