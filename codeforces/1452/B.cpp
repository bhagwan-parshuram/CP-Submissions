

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

bool check(lli mid,lli add,lli a[],int n){
	for(int i=0;i<n;i++){
		lli var=(n-1)*mid;
		if(a[i]!=(var-add+a[i])) return false;
	}

	return true;
}

void solve(){
	int n; cin>>n;
	lli a[n];
	lli add=0;
	lli maxi=INT_MIN;
	lli k=LLONG_MIN;
	frr(i,n) {
		cin>>a[i];
        add+=a[i];
        maxi=max(maxi,a[i]);

    }
    k=max((add+n-2)/(n-1),maxi);
    cout<<(n-1)*k-add<<endl;
    
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}