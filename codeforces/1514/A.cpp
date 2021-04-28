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
set<ll> s;
void solve(){
	int n;
	cin>>n;
	bool key=0;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		if(!s.count(x))key=1;
	}
	if(key)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}

int main(){
	fast;
	for(ll i=1;i*i<=10000;i++){
		s.insert(i*i);
	}
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
