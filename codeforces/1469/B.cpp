
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
	int n;
	cin>>n;
	int a[n+1];
	lli add=0;
	lli ans1=0;
	for(int i=0;i<n;i++){
       cin>>a[i];
       add+=a[i];
       ans1=max(ans1,add);
	}
	add=0;
	lli ans2=0;
	int m;cin>>m;
	int b[m+1];
	for(int i=0;i<m;i++){
       cin>>b[i];
       add+=b[i];
       ans2=max(ans2,add);
	}
	cout<<max(0LL,ans1+ans2)<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}