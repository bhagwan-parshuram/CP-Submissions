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
int d;
ll add;
int l[32];
int r[32];
void solve(){
	
	cin>>d>>add;
	
	ll sl=0;
	ll sr=0;
	for(int i=0;i<d;i++){
      cin>>l[i];
      cin>>r[i];
      sl+=l[i];
      sr+=r[i];
	}
	if(add>=sl && add<=sr){
		cout<<"YES"<<endl;
		int excess=add-sl;
		for(int day=0;day<d;day++){
			int available=r[day]-l[day];
			int canTake=min(available,excess);
			excess-=canTake;
			cout<<l[day]+canTake<<" ";
		}
		cout<<endl;
	}
	else cout<<"NO"<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
