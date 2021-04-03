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
	string a,b;
	cin>>a>>b;
	int z[n+1];
	int o[n+1];
	for(int i=0;i<=n;i++){
		z[i]=0;
		o[i]=0;
	}
	for(int i=0;i<n;i++){
		z[i]+=(a[i]=='0');
		o[i]+=(a[i]=='1');
		if(i){
			z[i]+=z[i-1];
			o[i]+=o[i-1];
		}
	}
	int key=1;
	for(int i=n-1;i>=0;i--){
		if(key){
			if(a[i]!=b[i] &&  z[i]!=o[i]){
				cout<<"NO"<<endl;
				return;
			}
			else if(a[i]!=b[i] &&  z[i]==o[i]){
				key=0;
			}
		}
		else{
			if(a[i]==b[i] &&  z[i]!=o[i]){
				cout<<"NO"<<endl;
				return;
			}
			else if(a[i]==b[i] &&  z[i]==o[i]){
				key=1;
			}
		}
	}
	cout<<"YES"<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
