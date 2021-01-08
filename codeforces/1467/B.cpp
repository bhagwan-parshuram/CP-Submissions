
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

#define Max 300005
#define mod 1000000007
#define INF 100000000000000000
int n;
int a[Max];
int score(int i){
	if(i<=1 || i>=n) return 0;

    if(a[i-1]>a[i] && a[i+1]>a[i]) return 1;
    if(a[i-1]<a[i] && a[i+1]<a[i]) return 1;

    return 0; 
}


void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];

    lli ans=0;
    lli out=0;
	for(int i=2;i<n;i++){
     ans+=score(i);
	}
	out=ans;
	//cout<<ans<<"@"<<endl;
	for(int i=2;i<n;i++){
		 lli curr=out;
         curr=curr-score(i-1)-score(i)-score(i+1);

         int temp=a[i];

         a[i]=a[i-1];

         curr=curr+score(i-1)+score(i)+score(i+1);
         ans=min(ans,curr);

         a[i]=temp;

         curr=out;

         curr=curr-score(i-1)-score(i)-score(i+1);

         a[i]=a[i+1];
         curr=curr+score(i-1)+score(i)+score(i+1);
         ans=min(ans,curr);

         a[i]=temp;


	}
	cout<<ans<<endl;

}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}