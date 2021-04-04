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


ll n;
ll a[200005];
bool check(ll len){
   //cout<<len<<"&"<<endl;
   ll p1=0;
   ll p2=len-1;
   if(a[p1]*2>=a[p2])return true;
   while(p2<n-1){
      p1++;
      p2++;
      if(a[p1]*2>=a[p2])return true;
   }
   return false;
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    ll ans=0;
    ll lo=0;
    ll hi=n;
    while(lo<=hi){
    	ll mid=(lo+hi)/2;
    	//cout<<check(mid)<<"*"<<endl;
    	if(check(mid)){
    		ans=mid;
    		lo=mid+1;
    	}
    	else hi=mid-1;
    }
    cout<<n-ans<<endl;

}

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t=1;
	while(t--)
	  solve();
}
