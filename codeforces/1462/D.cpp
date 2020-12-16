
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


int dp[15][90];

void solve(){
	lli n;
	cin>>n;
	lli a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	int p=1;
	int ans=1;
	while(p<=n){
		if(a[n]%a[p]==0){
			int k=2;
			int key=1;
			lli q=a[n]/a[p];
			lli temp=a[p]+a[p];
			while(temp!=a[n]){
				if(binary_search(a,a+n+1,temp)) k++;
				else{
					 key=0;
					 break;
					 
				}
				temp+=a[p];
			}
			if(key)ans=max(ans,k);
		}
		p++;
	}
	//cout<<(n-ans)<<" "<<ans<<endl;
	cout<<n-ans<<endl;
}



int main()
{
	fast;
    int t; cin>>t;

    for(int i=0;i<=9;i++) dp[i][0]=1;
    for(int i=1;i<=45;i++){
    	dp[0][i]=-1;
    }
    for(int i=1;i<=9;i++){
    	for(int j=1;j<=45;j++){
    		int ans1=dp[i-1][j-i];
            int ans2=dp[i-1][j];
            if(ans1==-1 && ans2==-1) dp[i][j]=-1;
            else if(ans1==-1) dp[i][j]=ans2;
            else if(ans2==-1) dp[i][j]=ans1;
            else
             dp[i][j]=dp[i-1][j-i]+dp[i-1][j];

    	}
    }
    
    while(t--) solve();
		
}