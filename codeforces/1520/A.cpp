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
	string s;
	cin>>s;
	int present[26];
	memset(present,0,sizeof(present));
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n && s[j]==s[i]){
			j++;
		}
		i=j-1;
		if(present[s[i]-'A']){
			//cout<<i<<endl;
			cout<<"NO"<<endl;
			return;
		}
		present[s[i]-'A']=1;
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
