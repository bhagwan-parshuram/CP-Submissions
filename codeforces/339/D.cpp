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
ll n,m;
ll tree[300001];
void build(){
	ll temp=n/2;
	ll curr=temp;
	for(ll i=n-1;i>0;i--){
		if(curr>0){
			tree[i]=(tree[i<<1] | tree[i<<1|1]);
			curr--;
			if(curr==0){
				curr=(-temp)/2;
				temp/=2;
			}
		}
		else{
			 tree[i]=(tree[i<<1]^tree[i<<1|1]);
			 curr++;
			 if(curr==0){
				curr=(temp)/2;
				temp/=2;
			}
		}
	}
}
void update(ll p,ll x){
	tree[p+n]=x;
	p+=n;
	bool flag=1;
	while(p>1){
		if(flag)tree[p/2]=(tree[p] | tree[p^1]);
		else tree[p/2]=(tree[p]^tree[p^1]);
		flag=1^flag;
		p/=2;
	}
}
void solve(){
	cin>>n>>m;
	ll temp=1;
	while(n--)temp*=2;
	n=temp;
	for(int i=0;i<n;i++){
		cin>>tree[i+n];
	}
	build();
	// for(int i=1;i<2*n;i++){
	// 	cout<<tree[i]<<" ";
	// }
	// cout<<endl;
	// update(0,tree[n]);
	// for(int i=1;i<2*n;i++){
	// 	cout<<tree[i]<<" ";
	// }
	// cout<<endl;
	while(m--){
		ll p,b;
		cin>>p>>b;
		p--;
		update(p,b);
		cout<<tree[1]<<endl;
	}
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
