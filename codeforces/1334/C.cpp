#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
using lli = long long;
#define Max 100005
#define mod 1000000007
#define  F first 
#define  S  second 
#define  pb push_back


void solve(){
	lli n; cin>>n;
	lli a[n],b[n];
	lli c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	lli curr=0;
	lli ans=LLONG_MAX;
	for(lli i=0;i<n;i++){
		c[i]=max(a[i]-b[(i-1+n)%n],0LL);
		curr+=c[i];
	}
	for(int i=0;i<n;i++){
		ans=min(ans,curr+min(a[i],b[(i-1+n)%n]));
	}
	cout<<ans<<endl;


}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
		
}