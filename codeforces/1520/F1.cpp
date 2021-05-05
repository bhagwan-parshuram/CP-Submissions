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
	ll n,t,k;
	cin>>n>>t>>k;
	ll lo=1;
	ll hi=n;
	ll ans=n;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		cout<<"? "<<lo<<" "<<mid<<endl;
		fflush(stdout);
		ll left;
		cin>>left;
		//cout<<"? "<<mid+1<<" "<<hi<<endl;
       // fflush(stdout);
        // ll right;
        // cin>>right;
        left=(mid-lo+1)-left;
        // right=(hi-mid)-right;
        if(k>left){
          lo=mid+1;
          k-=left;
        }
        else{
        	ans=mid;
        	hi=mid-1;
        }

	}
	cout<<"! "<<ans<<endl;
}

int main(){
	//fast;
	int t=1;
	while(t--)
	  solve();
}
