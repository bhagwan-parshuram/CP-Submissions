#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<pll> vpll; 
 
#define endl '\n' 
#define fast std::ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
ll n; ll a[5005]; ll b[5005]; ll dp[5005]; ll r[5005][5005]; ll rev(int i,int j){if(i>j)return 0; if(i==j)return a[i]*b[i]; ll &ans=r[i][j]; if(ans!=-1)return ans; ans=rev(i+1,j-1)+a[i]*b[j]+a[j]*b[i]; return ans; } void solve(){cin>>n; for(int i=0;i<n;i++)cin>>a[i]; for(int j=0;j<n;j++)cin>>b[j]; memset(dp,-1,sizeof(dp)); memset(r,-1,sizeof(r)); for(int i=0;i<n;i++)r[i][i]=a[i]*b[i]; for(int i=0;i<n;i++){for(int j=i+1;j<n;j++){if(r[i][j]==-1){rev(i,j); } } } for(int i=0;i<n;i++){dp[i]=a[i]*b[i]; if(i)dp[i]+=dp[i-1]; } ll ans=dp[n-1]; for(int i=0;i<n;i++){for(int j=i+1;j<n;j++){ll temp=r[i][j]; if(i)temp+=dp[i-1]; if(j<n-1)temp+=dp[n-1]-dp[j]; ans=max(ans,temp); } } cout<<ans<<endl; } int main(){fast; int t=1; while(t--) solve(); }