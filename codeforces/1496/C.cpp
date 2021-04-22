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
	vector<ll> miners,mines;
	ll neutral=0;
	for(int i=0;i<2*n;i++){
        ll x,y;
        cin>>x>>y;
        if(x==0 && y==0){
         neutral++;
        }
        else if(x==0){
        	miners.pb(abs(y));
        }
        else mines.pb(abs(x));
	}
	while(miners.size()!=n)miners.pb(0);
	while(mines.size()!=n)mines.pb(0);
	sort(mines.begin(),mines.end());
	sort(miners.begin(),miners.end());

	long double ans=0;
	for(int i=0;i<n;i++){
		ans+=sqrt((1.0*miners[i]*miners[i])+(1.0*mines[i]*mines[i]));
	}
	cout<<setprecision(15)<<ans<<endl;

}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}