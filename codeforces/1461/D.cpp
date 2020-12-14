
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

vector<lli> v;
vector<int> a;
int n,q,s;
vector<lli> arr;

void fun(int lo, int hi){
	    arr.push_back(v[hi+1]-v[lo]);
	    
	    if(a[lo]==a[hi]) return;

	    
        int toSearch=(a[lo]+a[hi])/2;
        int mid=upper_bound(all(a),toSearch)-a.begin();

        lli sum1,sum2;
        sum1=v[mid]-v[lo];
        sum2=v[hi+1]-v[mid];
        arr.pb(sum1);
        arr.pb(sum2);

         fun(lo,mid-1);
         fun(mid,hi);


}

void solve(){
	cin>>n>>q;
	a.clear();
	a.resize(n);
	arr.clear();

	frr(i,n) cin>>a[i];
    sort(all(a));

    v.clear();
    v.resize(n+1);
    rep(i,1,n){
    	v[i]=a[i-1]+v[i-1];
    }
    fun(0,n-1);
    sort(all(arr));
    while(q--){
    	cin>>s;
    	if(binary_search(all(arr),s))cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
    	

    }

}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}