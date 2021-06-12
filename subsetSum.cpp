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
ll a[3030];
ll n,s;
ll dp[3030][3030];
ll mod=1e9+7;
ll fun(ll i,ll j){
    if(i==n){
        if(j==s)return 1;
        else return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans=0;

    ans=(2*fun(i+1,j))%mod;
    if(j+a[i]<=s)ans=ans+fun(i+1,j+a[i])%mod;
    ans%=mod;
    return dp[i][j]=ans;
}
void solve(){
    cin>>n>>s;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=fun(0,0);
    cout<<ans<<endl;
}

int main(){
   fast;
   clock_t begin = clock();
   ll tc=1;cin>>tc;
   for(ll i=1;i<=tc;i++){
       //cout<<"Case #"<<i<<": ";
       solve();
   }
    clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
}
