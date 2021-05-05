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
	ll ans=0;
	string s="123456789";
	//if(n==(1000000000))n--;
	for(int i=0;i<9;i++){
		string c="";
		c+=s[i];
		ll curr=stoll(c);
        while( curr<=n){
        	ans++;
        	c+=s[i];
        	curr=stoll(c);
        }
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
