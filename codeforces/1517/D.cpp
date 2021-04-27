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
ll n,m,k;
ll h[501][501];
ll v[501][501];
ll dp[501][501][21];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool check(int x,int y){
    if(x>=n || x<0 || y<0 || y>=m)return false;
    return true;
}
ll fun(int i,int j,int times){
	if(times>=k)return 0;

	ll &ans=dp[i][j][times];
	if(ans<(ll)1e18)return ans;
	if(check(i+1,j))ans=min(ans,fun(i+1,j,times+1)+v[i][j]);
	if(check(i-1,j))ans=min(ans,fun(i-1,j,times+1)+v[i-1][j]);
	if(check(i,j+1))ans=min(ans,fun(i,j+1,times+1)+h[i][j]);
	if(check(i,j-1))ans=min(ans,fun(i,j-1,times+1)+h[i][j-1]);
	return ans;

}
void solve(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j+1<m;j++)cin>>h[i][j];
	}
    for(int i=0;i+1<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>v[i][j];
    	}
    }
    if(k&1){
    	for(int i=0;i<n;i++){
    	   for(int j=0;j<m;j++){
    		cout<<-1<<" ";
    	   }
    	cout<<endl;
        }
     return;
    }
    k/=2;
    for(int i=0;i<=n;i++){
    	       for(int j=0;j<=m;j++){
    		      for(int l=0;l<=k;l++){
    			      dp[i][j][l]=1e18;
    		       }	
    	    }
    }
    for(int x=0;x<n;x++){
    	for(int y=0;y<m;y++){
        cout<<2*fun(x,y,0)<<" ";
        }
    cout<<endl;
    }


}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
