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

void solve(){
	ll n;
	ll q;
	cin>>n;
	if((n%2050)!=0){
		cout<<-1<<endl;
		return;
	}
	else{
		q=(n/2050);
		ll ans=0;
		while(q>0){
			ans+=(q%10);
			q/=10;
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
