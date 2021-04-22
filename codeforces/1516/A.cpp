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
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=0;i<n;i++)cin>>a[i];
	int p1=0;
    int p2=n-1;
    while(k>0 && p1<n-1){
    	int mini=min(a[p1],k);
    	a[p2]+=mini;
    	k-=mini;
    	a[p1]-=mini;
    	p1++;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
