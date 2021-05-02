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
ll n,x;
cin>>n>>x;
ll a[n+1];
ll ans=0;
for(int i=0;i<n;i++)cin>>a[i],ans+=a[i];
if(ans==(x)){
	cout<<"NO"<<endl;
	return;
}
cout<<"YES"<<endl;
ll add=0;
int i=0;
while(i<n){
	if((add+a[i])!=x){
		cout<<a[i]<<" ";
		add+=a[i];
		i++;
	}
	else{
		cout<<a[i+1]<<" "<<a[i]<<" ";
        add+=a[i+1];
        add+=a[i];
        i+=2;
	}

}
cout<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
