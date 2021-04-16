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
	int n;
	cin>>n;
	n*=2;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int final=1e8;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int ans=0;
			vi v;
			for(int k=0;k<n;k++){
				if(k==i || k==j)continue;
				v.pb(a[k]);
				//cout<<*v.rbegin()<<" ";
			}
			// cout<<endl;
			for(int k=1;k<v.size();k+=2){
				ans+=v[k]-v[k-1];
			}
			//cout<<"ANs "<<ans<<endl;
			final=min(final,ans);
		}
	}
	cout<<final<<endl;
}

int main(){
	fast;
	int t=1;
	//cin>>t;
	while(t--)
	  solve();
}
