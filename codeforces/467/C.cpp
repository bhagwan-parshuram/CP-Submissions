#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
using lli = long long;
#define Max 5005
#define mod 1000000007
#define  F first 
#define  S  second 
#define  pb push_back

lli n,m,k;
lli a[Max];
lli dp[Max][Max];
lli bag[Max];

lli fun(int s,int K){
   
   if(K<=0 || s<m) return 0;

   if(dp[s][K]>0) return dp[s][K];

   lli ans=max(fun(s-m,K-1)+bag[s]-bag[s-m],fun(s-1,K));
   dp[s][K]=ans;
   return ans;


}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
   
    cin>>n>>m>>k;
    
    for(int i=1;i<=n;i++){
     cin>>a[i];
     bag[i]=bag[i-1]+a[i];	
    }
    for(int i=1;i<=k;i++){
    	for(int j=m;j<=n;j++){
    		dp[i][j]=max(dp[i-1][j-m]+bag[j]-bag[j-m],dp[i][j-1]);
    	}
    }

   

    cout<<dp[k][n]<<endl;
		
}