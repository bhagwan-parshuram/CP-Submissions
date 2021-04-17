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
ll dp[2001][2001];
ll a[2001];
ll fun(int l,int r){
    if(l==r)return 0;
	ll &ans=dp[l][r];
	if(ans!=-1)return ans;
	ans=min(fun(l+1,r),fun(l,r-1))+(a[r-1]-a[l-1]);
	return ans;
}
void solve(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
    memset(dp,-1,sizeof(dp));
    cout<<fun(1,n)<<endl;

    
}
//tmtttmmmt
int main(){
	fast;
    int t=1;
	while(t--)
	  solve();
}
