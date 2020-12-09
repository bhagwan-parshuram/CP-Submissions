#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
using lli = long long;
#define Max 100005
#define mod 1000000007
#define  F first 
#define  S  second 
#define  pb push_back





int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    lli y,k,n;
    cin>>y>>k>>n;
    lli count=0;
    for(lli ans=((y+k-1)/k)*k;ans<=n;ans+=k){
    	if(ans<=n && ans>y){
    		cout<<ans-y<<" ";
    		count++;
    	}

    }
    if(count==0)cout<<-1<<" ";
    cout<<endl;
		
}