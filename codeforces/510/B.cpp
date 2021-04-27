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
string a[55];
ll n,m;
int visited[55][55];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
bool check(int i,int j,int ni,int nj){
	if(ni<0 || ni>=n || nj<0 || nj>=m){
		//cout<<"*"<<endl;
		return false;
	}
	//cout<<i<<" "<<j<<" "<<a[ni][nj]<<(a[i][j]!=a[ni][nj])<<endl;
	if(a[i][j]!=a[ni][nj]){
		//cout<<"#"<<endl;
		return false;
	}
	return true;
}
bool dfs(int c,int i,int j,int pi,int pj){
	bool ans=0;
    visited[i][j]=1;
    for(int dir=0;dir<4;dir++){
    	int ni=i+dx[dir];
    	int nj=j+dy[dir];
    	//cout<<check(i,j,ni,nj)<<endl;
    	if(check(i,j,ni,nj)){
            //cout<<visited[ni][nj]<<endl;
    		if((!visited[ni][nj])){

    		ans|=dfs(c+1,ni,nj,i,j);
    		//cout<<"*";
    	}
    	else if((visited[ni][nj])){
    		//cout<<"*"<<endl;
    		if(!(ni==pi && nj==pj) && c>3)ans=1;
    	 }
    	}
    }
    return  ans;
}
void solve(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  bool ans=0;
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		if(!visited[i][j])ans|=dfs(1,i,j,-1,-1);
  	}
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
