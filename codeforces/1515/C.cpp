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
	ll n,m,x;
	cin>>n>>m>>x;
	pll h[n+1];
	ll curr[m+1];
	ll ans[n+1];
	for(int i=0;i<n;i++){
		cin>>h[i].first;
		h[i].second=(i);
	}
	sort(h,h+n,greater<pll>());
    priority_queue<pll>pq;
    ll maxi=-1;
    for(int i=0;i<m;i++){
    	pq.push({-h[i].first,i+1});
    	maxi=max(h[i].first,maxi);
    	ans[h[i].second]=i+1;
    }
    for(int i=m;i<n;i++){
     ll curr=pq.top().first;
     ll ind=pq.top().second;
     curr*=(-1);
     curr+=(h[i].first);
     maxi=max(maxi,curr);
     ans[h[i].second]=ind;
     pq.pop();
     pq.push({-curr,ind});

    }
    ll mini=-pq.top().first;
    if(maxi-mini<=x){
    	cout<<"YES"<<endl;
    	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    	cout<<endl;
    }
    else cout<<"NO"<<endl;

}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
