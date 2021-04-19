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
	map<string,int>mp;
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		mp[s]++;
		if(mp[s]>1){
			s+=(to_string(mp[s]-1));
			cout<<s<<endl;
		}
		else cout<<"OK"<<endl;
	}
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
