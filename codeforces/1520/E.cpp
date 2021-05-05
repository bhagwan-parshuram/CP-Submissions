#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
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
ll distance(vi &v,ll ind){
    ll ans=0;
    ll n=v.size();
    vi a;
    for(ll i=1;i<=ind;i++){
      a.pb(v[i]-v[i-1]-1);
    }
    ll add=0;
    reverse(a.begin(),a.end());
    for(ll i=1;i<a.size();i++){
    	a[i]+=a[i-1];
    }
    for(ll i=0;i<a.size();i++){
    	add+=a[i];
    }
    ans+=add;
    vi b;
    for(ll i=ind+1;i<n;i++){
      b.pb(v[i]-v[i-1]-1);
    }
    for(ll i=1;i<b.size();i++){
        b[i]+=b[i-1];
    }
    for(ll i=0;i<b.size();i++){
    	ans+=b[i];
    }
    return ans;
}
void solve(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	vi v;
	for(ll i=0;i<n;i++){
		if(s[i]=='*')v.pb(i);
	}
	n=v.size();
	if(n&1){
		cout<<distance(v,n/2)<<endl;
	}
	else{
		cout<<min(distance(v,(n-1)/2),distance(v,n/2))<<endl;
	}

}

int main(){
	fast;
	ll t=1;
	cin>>t;
	while(t--)
	  solve();
}
