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
int n;
int placed[16];
int backtrack(int row,int cnt){
   if(cnt==n)return 1;
   if(row==n)return 0;
   int ans=0;
   for(int c=0;c<n;c++){
     bool safe=1;
     for(int i=0;i<row;i++){
        int col=placed[i];
        if(col==c || abs(row-i)==abs(col-c) ||(abs(i-row)==2 && abs(col-c)==1) || (abs(row-i)==1 and abs(col-c)==2))safe=0;
     }
     if(safe){
        placed[row]=c;
        ans+=backtrack(row+1,cnt+1);
     }

    }
    return ans;
}

void solve(){
    cin>>n;
    cout<<backtrack(0,0)<<endl;
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
