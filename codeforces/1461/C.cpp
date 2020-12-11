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
	int n,m; cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
    int index=-1;
      for(int i=n-1;i>=index;i--){
    	if(a[i]!=(i+1)){
    		index=i;
    	}
    }

    double ans=1;
    for(int i=0;i<m;i++){
      int temp;
      double pr;
      cin>>temp>>pr;
      if(temp-1>=index) ans*=(1-pr);
      }
    
  
    if(index!=-1)
    cout<<fixed<<setprecision(6)<<1-ans<<endl;
    else cout<<fixed<<setprecision(6)<<1.000000<<endl;


}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
		
}