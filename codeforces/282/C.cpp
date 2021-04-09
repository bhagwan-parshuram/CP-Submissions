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
	string a,b;
	cin>>a>>b;
    int n=a.size();
	// 11-->01 10
	// 00-->00
	// 10/01--11
	int n1=a.size();
	int n2=b.size();
	if(n1!=n2){
		cout<<"NO"<<endl;
		return;
	}

	bool ans=1;
	bool needChange=0;
	bool has1=0;
	bool allZeroes=1;
	for(int i=n-1;i>=0;i--){
	  if(a[i]!=b[i]){
	  	needChange=1;
	  }
	  if(b[i]!='0')allZeroes=0;
	  if(a[i]=='1')has1=1;
	}
	if(allZeroes && needChange)ans=0;
	if(needChange  && !has1) ans=0;
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
