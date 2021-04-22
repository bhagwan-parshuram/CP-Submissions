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
ll n;
ll a[1001];
ll dp[105][200005];
ll add;
void solve(){
 cin>>n;
 for(int i=0;i<n;i++)cin>>a[i],add+=a[i];
 if(add&1){
 	cout<<0<<endl;
 	return ;
 }
 ll toget=add/2;
 dp[0][0]=1;
 for(int i=0;i<=n;i++){
 	for(int j=0;j<=toget;j++){
 		if(dp[i][j]==1){
 			if(j+a[i]<=toget)dp[i+1][j+a[i]]=1;
 			dp[i+1][j]=1;
 		}
 	}
 }
 if(dp[n][toget]==1){
 	cout<<1<<endl;
 	int index=0;
 	int pos=__builtin_ctz(a[index]);
 	for(int i=1;i<n;i++){
       int num=__builtin_ctz(a[i]);
       if(num<pos){
       	index=i;
       	pos=num;
       }
 	}
 	cout<<index+1<<endl;
 }
 else cout<<0<<endl;
 
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
