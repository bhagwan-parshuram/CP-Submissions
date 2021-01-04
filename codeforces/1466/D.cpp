
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
	int n; cin>>n;
	lli w[n+1];
	w[0]=-1;
	lli add=0;
	for(int i=1;i<=n;i++) {
		cin>>w[i];
		add+=w[i];
	}
	vector<int> tree(n+1);
   
    for(int i=1;i<n;i++){
    	int x,y;
    	cin>>x>>y;
    	tree[x]++;
    	tree[y]++;

    }
    priority_queue<lli> pq;
    for(int i=1;i<=n;i++){
    	if(tree[i]>1){
    		while(tree[i]>1){
    			pq.push(w[i]);
    			tree[i]--;
    		}
    	}
    }
    for(int i=1;i<n;i++){
    	if(i>1){
    	if(pq.size()>0)
    	  {
    	  	 add+=pq.top();
    	  pq.pop();
    	  
    	  }
    	  cout<<add<<" ";
    	}
    	else cout<<add<<" ";
    }
    cout<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}