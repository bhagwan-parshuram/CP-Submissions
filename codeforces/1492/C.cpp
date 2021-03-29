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
	int n,m;
	cin>>n>>m;
	string s1,s2;
	cin>>s1>>s2;

	int left[n+1];
	int right[n+1];
	int p2=0;
	int p1=0;
	while(p2<m){
      if(s1[p1]==s2[p2]){
      	left[p2]=p1;
      	//cout<<"*p1"<<p1;
      	p2++;
      }
      p1++;
	}
	p1=n-1;
	p2=m-1;
	while(p2>=0){
		if(s1[p1]==s2[p2]){
      	right[p2]=p1;
      	p2--;
      }
      p1--;
	}
	// for(int i=0;i<26;i++){
	// 	cout<<left[i]<<" "<<right[i]<<endl;
	// }
	int ans=0;
	for(int i=1;i<m;i++){
		int curr=right[i]-left[i-1];
		ans=max(ans,curr);
	}
	cout<<ans<<endl;
}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
