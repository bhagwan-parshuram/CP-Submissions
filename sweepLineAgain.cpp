#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include<cstring>
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
    ll n,l;
    cin>>n>>l;

    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
  //minimum interval with union equal to [0,l)
    sort(v.begin(),v.end());
    ll cnt=0;
    ll end=0;
    for(int i=0;i<n && end<l;){
        ll curr=end;
        while(i<n  && v[i].first<=curr){
            end=max(end,v[i].second);
            i++;
        }
        cnt++;
    }
    cout<<cnt<<endl;
}

int main(){
   fast;
   //clock_t begin = clock();
   ll tc=1;//cin>>tc;
   for(ll i=1;i<=tc;i++){
       //cout<<"Case #"<<i<<": ";
       solve();
   }
   //clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;

}
