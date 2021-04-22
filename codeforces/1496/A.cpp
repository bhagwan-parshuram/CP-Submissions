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
   string s1,s2;
   cin>>s1;
   s2=s1;
   reverse(s1.begin(),s1.end());
   int len=0;
   int m;
   if(n&1)m=(n)/2;
   else m=(n-1)/2;
   for(int i=0;i<m;i++){
   	if(s1[i]!=s2[i])break;
   	else len++;
   }
   //cout<<len<<endl;
   if(len>=k)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
