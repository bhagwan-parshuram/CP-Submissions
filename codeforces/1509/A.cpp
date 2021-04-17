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

void printV(vi v){
  for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}
void solve(){
	int n;
	cin>>n;
	vi odd,even;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
	    if(x&1)odd.pb(x);
	    else even.pb(x);
	}
	printV(odd);
	printV(even);
	cout<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
