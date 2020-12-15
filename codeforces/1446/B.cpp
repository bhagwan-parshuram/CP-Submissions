
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




int main()
{
	fast;
    int n,m;
    string s1,s2;
    cin>>n>>m>>s1>>s2;

    lli dp[n+3][m+2];
    mem(dp,0);
    lli ans=LLONG_MIN;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(s1[i-1]==s2[j-1]){
    			dp[i][j]=dp[i-1][j-1]+2;
    		}
    		else{
    			dp[i][j]=max(0LL,max(dp[i-1][j],dp[i][j-1])-1);
    		}
    		ans=max(ans,dp[i][j]);
    	}

    }
   // lli ans=1;
   // ans=4*dp[n][m]-n-m;

    cout<<ans<<endl;
		
}