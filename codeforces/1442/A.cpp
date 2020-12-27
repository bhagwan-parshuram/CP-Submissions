
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
	int a[n];
	lli diff=0;
	int key=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i){
			if(a[i]>a[i-1]){
				diff+=(a[i]-a[i-1]);
			}
			if(a[i]-diff<0){
				key=0;
			}
			//cout<<diff<<" ";
		}
	}
	if(key)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}