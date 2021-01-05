
#include<bits/stdc++.h>
using namespace std; 
#include<string.h>

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define f first
#define sc second
#define mk make_pair
#define in insert
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using lli = long long;
#define ii pair<lli,lli>

#define Max 100005
#define mod 1000000007
#define INF 100000000000000000

ii fun(ii p,char c){
	if(c=='L') p.f--;
	if(c=='R') p.f++;
    if(c=='U') p.sc++;
    if(c=='D') p.sc--;
    return p;
}

void solve(){
	string s;
	vector<ii> v;
	cin>>s;
	ii p={0,0};
	for(int i=0;i<s.size();i++){
      p=fun(p,s[i]);
      if(p!=make_pair(0LL,0LL)) v.pb(p);
	}
	
	ii ans={0,0};
	frr(i,v.size()){
		ii curr={0,0};
		frr(j,s.size()){
          if(fun(curr,s[j])!=v[i])
          	curr=fun(curr,s[j]);
		}
		if(curr==make_pair(0LL,0LL)){
            ans=v[i];
            break;
		}
	}
	cout<<ans.f<<" "<<ans.sc<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}