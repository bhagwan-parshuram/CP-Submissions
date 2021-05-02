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
	cin>>n;
	if(n&1)cout<<"NO"<<endl;
	else{
		n/=2;
		for(ll i=1;i*i<=n;i++){
			if((i*i)==n){
				cout<<"YES"<<endl;
				return;
			}
		}
		if(n&1){
			cout<<"NO"<<endl;
			return;
		}
		n/=2;
		for(int i=1;i*i<=n;i++){
			if((i*i)==n){
				cout<<"YES"<<endl;
				return;
			}
		}
		cout<<"NO"<<endl;
	}
}

int main(){
	fast;
	int t;
	cin>>t;
	while(t--)
	  solve();
}
