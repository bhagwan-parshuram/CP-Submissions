
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
#define INF INT_MAX
#define ii pair<int,int>

void solve(){
	int n;
	cin>>n;
	vector<pair<pair<int,int>,int>> v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({{x,-y},i});
		v.pb({{y,-x},i});

	}
	sort(all(v));
    vector<int>ans(n,-1);
    int W=INT_MAX;
    int id=-1;
    for(auto curr:v){
    	int h=curr.fr.fr;
    	int w=-curr.fr.sc;
    	int index=curr.sc;
    	if(w>W){
    		ans[index]=id+1;
    	}
    	else if(w<W){
    		id=index;
    		W=w;
    	}
    }
   for(int i=0;i<n;i++){
   	cout<<ans[i]<<" ";
   }

	cout<<endl;
	
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}