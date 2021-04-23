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
	int n;
	cin>>n;
	int a[n+1][n+1];
	for(int i=1;i<=n;i++)cin>>a[i][i];
	int p=0;
    //cout<<"*"<<endl;
    for(int i=1+p;i<=(n);i++){
    	int j=i;
    	int pos;
    	while(a[j][j-p]!=(1+p)){
    		j++;
    	}
    	//cout<<j<<"*"<<endl;
    	pos=j;
    	for(int k=i;k<pos;k++){
    		a[k+1][k-p]=a[k][k-p];
    	}
    	for(int k=pos+1;k<=n;k++){
    		a[k][k-p-1]=a[k][k-p];
    	}
    	p++;
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(j<=i)cout<<a[i][j]<<" ";
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
