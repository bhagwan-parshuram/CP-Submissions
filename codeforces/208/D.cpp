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
	ll p[n+1];
	ll cost[5];
	ll quantity[5];
    
    for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<5;i++)cin>>cost[i],quantity[i]=0;
	
    ll curr=0;
    ll p1=0;
    while(p1<n){
    	curr+=p[p1];
        for(int i=4;i>=0;i--){
        	ll q=(curr)/(cost[i]);
        	ll num=cost[i]*q;
            quantity[i]+=q;
            curr-=num;
        }
        p1++;
    }
    for(int i=0;i<5;i++)cout<<quantity[i]<<" ";
    cout<<endl;
    cout<<curr<<endl;

}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
