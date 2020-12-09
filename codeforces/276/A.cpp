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
	
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    lli n,k; cin>>n>>k;
    lli f[n],t[n];

    for(int i=0;i<n;i++){
    	cin>>f[i]>>t[i];
    }
    lli ans=INT_MIN;
    for(int i=0;i<n;i++) ans=max(ans,f[i]-max(t[i]-k,0LL));

    cout<<ans<<endl;



		
}