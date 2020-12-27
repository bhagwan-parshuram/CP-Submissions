
#include<bits/stdc++.h>
using namespace std; 
#include<string.h>

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fr first
#define sc second
#define mk make_pair
#define in insert
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using lli = long long;

#define Max 100005
#define mod 1000000007
#define INF 100000000000000000


void solve(){
	int n; cin>>n;
	vector<pair<lli,lli>> v,v1;
	for(int i=0;i<n;i++){
		lli l,r;
		cin>>l>>r;
		v.pb({l,r});
		v1.pb({r,l});
	}
    
	sort(all(v));
	sort(all(v1));
	int ans=1e9;
	for(auto s:v){
		lli l=s.fr;
        lli r=s.sc;
        int n1=lower_bound(v1.begin(),v1.end(),make_pair(l,0LL))-v1.begin();
        int n2=n-(upper_bound(v.begin(),v.end(),make_pair(r,lli(1e9+1)))-v.begin());
        ans=min(ans,n1+n2);

	}
	cout<<ans<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}