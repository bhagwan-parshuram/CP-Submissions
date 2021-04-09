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
	// x      y       z       a
	// 1000-x  1000-y 1000-z  1000-a
	// abs(1--n)*1000 -(x+y+z+a)<=500
	ll add=0;
	ll a[n+1];
	ll g[n+1];
	for(int i=0;i<n;i++){
     ll x,y;
     cin>>a[i];
     cin>>g[i];
     x=a[i];
     add+=x;
	}
	bool ans=0;
	char s[n+1];
	for(ll i=0;i<=n;i++){
      if(abs(i*1000-add)<=(500)){
      	ans=1;
        for(int j=0;j<i;j++){
        	s[j]='G';

        }
        for(int j=i;j<n;j++){
            s[j]='A';
        }
        break;
      }
	}
	if(ans){
		for(int i=0;i<n;i++)cout<<s[i];
	}
   else cout<<-1;
   cout<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
