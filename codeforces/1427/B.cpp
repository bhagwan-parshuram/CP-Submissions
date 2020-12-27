
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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	lli ans=0;
    if(s[0]=='W') ans+=1;

    int c=0;
    if(s[0]=='L') c++;
    
    string curr="L";
    for(int i=1;i<n;i++){
    	curr+='L';
       if(s[i]=='W') ans+=1;
       if(s[i-1]=='W' && s[i]=='W') ans++;
       if(s[i]=='L') c++;
    }
    if(s==curr){
    	cout<<max(2*(min(c,k))-1,0)<<endl;
    	return;
    }
    ans+=2*(min(c,k));
    vector<int> seg;
    for(int i=1;i<n;++i){//LLR
    	if(s[i]=='L' && s[i-1]=='W'){
    		int j=i;
    		int l=0;
            while(s[j]=='L' && j<n){
             l++;
             j++;
            // cout<<l<<" ";
           }
           i=j-1;
           if(j<n && s[j]=='W')
            seg.pb(l);
    	}
    }
    sort(all(seg));

    	for(int i=0;i<seg.size();i++){
    		if(seg[i]<=k) ans++;
    		k-=seg[i];
            if(k<=0) break;
    		
    	}

    cout<<ans<<endl;

}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}