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
	if(n==2)cout<<-1<<endl;
	else{
		int k=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
               cout<<k<<" ";
               k+=2;
               if(k>(n*n)){
               	k=2;
               }
			}
			cout<<endl;
		}
	}
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
