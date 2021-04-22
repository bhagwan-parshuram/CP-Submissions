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
	ll n;
	cin>>n;
	unsigned long long a[n+1],b[n+1];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		a[i]^=a[i-1];
	}
	for(int i=n;i>1;i--)b[i-1]^=b[i];
	bool key=0;
	// for(int i=1;i<n;i++){
	//   if(a[i]==(a[n]^a[i])){
	//   	key=1;
	//   	break;
	//   }
	// }
	for(int i=1;i<n;i++){
		for(int j=n;j>i;j--){
			if(a[i]==b[j] && a[i]==(a[n]^a[i]^b[j])){
				key=1;
				break;
			}
		}
	}

    
	if(a[n]==0)key=1;
	if(key)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}


int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
