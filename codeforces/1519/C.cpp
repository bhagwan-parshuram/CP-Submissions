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
	vpll v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].second;
	}
	ll add=0;
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		add+=v[i].first;
	}
	unordered_map<ll,vll> bag;
	for(auto u:v){
		bag[u.second-1].pb(u.first);
	}
	for(auto u: bag){
		int i=u.first;
		sort(bag[i].begin(),bag[i].end(),greater<ll>());
		int sz=bag[i].size();
		for(int j=1;j<sz;j++){
			//cout<<bag[i][j]<<" ";
			bag[i][j]+=bag[i][j-1];
		}
		//cout<<endl;
	}
	ll ans[n+1];
	memset(ans,0,sizeof(ans));

    for(auto u:bag){
            int i=u.first;
			int sz=bag[i].size();
			for(int j=1;j<=sz;j++){
				int rem=(sz%j);
				ans[j]+=bag[i][sz-1-rem];
				 //if((sz-1-rem)>=0)ans[j]-=bag[i][sz-1-rem];

			}
		}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<endl;

}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
