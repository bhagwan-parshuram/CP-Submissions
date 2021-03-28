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

void solve(){
	int n,q,c;
	cin>>n>>q>>c;

	
	ll dp[101][101][11];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		int x,y,s;
        cin>>x>>y>>s;
        dp[x][y][s]++;
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int s=0;s<=c;s++){
                dp[i][j][s]+=dp[i-1][j][s]+dp[i][j-1][s]-dp[i-1][j-1][s];
			}
		}
	}

    while(q--){
          ll m,x1,x2,y1,y2;
          cin>>m>>x1>>y1>>x2>>y2;
          ll ans=0;
          for(int i=0;i<=c;i++){
          	ll curr=(m+i)%(c+1);
            ans+=(dp[x2][y2][i]-dp[x1-1][y2][i]-dp[x2][y1-1][i]+dp[x1-1][y1-1][i])*curr;
          }
          cout<<ans<<endl;
    }

}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
