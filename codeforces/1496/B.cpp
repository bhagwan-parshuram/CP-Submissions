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
	int n,k;
	cin>>n>>k;

	ll a[n+1];
	set<ll> s;
	for(int i=0;i<n;i++)cin>>a[i],s.insert(a[i]);
	int distinct=s.size();
    sort(a,a+n);
    ll miss=0;
    for(auto u:s){
       if(u!=miss)break;
       else miss++;
    }
    ll maxi=a[n-1];
    if(k>0){
    	if(miss<maxi){
    	if(!(s.count((miss+maxi+1)/2)))
    	distinct++;
    }
    else distinct+=k;
    }
    cout<<distinct<<endl;
	
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
