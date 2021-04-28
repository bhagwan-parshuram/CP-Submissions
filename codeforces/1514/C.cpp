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
	vi v;
	ll temp=n;
	for(int i=2;n>1;i++){
		bool flag=1;
		while((n%i)==0){
			if(flag)v.pb(i);
			n/=i;
			flag=0;
		}
	}
	n=temp;
	set<int> ans;
	ll prod=1;
	ans.insert(1);
	for(int i=2;i<n;i++){
		bool flag=1;
		for(auto u: v){
			if((i%u)==0){
				flag=0;
				//cout<<u<<" "<<i<<endl;
			}
		}
		if(flag){
			ans.insert(i);
			prod*=i;
			prod%=n;
		}
	}
	if((prod%n)!=1){
		int m=(prod%n);
		ans.erase(m);
	}
	cout<<ans.size()<<endl;
	for(auto u: ans)cout<<u<<" ";
		cout<<endl;

}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
