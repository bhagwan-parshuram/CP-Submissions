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
    multiset<ll> v;
    int key=0;
    ll add=0;
    ll maxi=-1;
    for(int i=0;i<n;i++){
      ll x;
      cin>>x;
      add+=x;
      maxi=max(maxi,x);
    }
    add-=maxi;
    if(add>=maxi && ((add+maxi)%2)==0)key=1;
 
    
    if(key)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--)
      solve();
}
