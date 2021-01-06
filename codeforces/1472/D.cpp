
#include<bits/stdc++.h>
using namespace std; 
#include<string.h>

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fr first
#define sc second
#define mk make_pair
#define in insert
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using lli = long long;

#define Max 100005
#define mod 1000000007
#define INF 100000000000000000

void solve(){
	int n;
	cin>>n;
	int a[n];
	lli s1=0,s2=0;
	frr(i,n)cin>>a[i];
	sort(a,a+n,greater<int>());
    for(int i=0;i<n;i+=2){
    	if((a[i]&1)==0){
          s1+=a[i];
    	}
    	if((i+1<n) && (a[i+1]&1)){
          s2+=a[i+1];
    	}
    }
    if(s1==s2)cout<<"Tie"<<endl;
    else if(s1>s2)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}