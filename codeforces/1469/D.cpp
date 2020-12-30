
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
	lli n;
	cin>>n;
	int count=0;
	int N=n;
	int c=0;
	for(int i=n;i>=2;i--){
		if(i!=2 && i!=4 && i!=8 && i!=n){
			//cout<<i<<" "<<n<<endl;
			c++;
		}
	}
	int m=n;
	
	if(n>8){
		while(n>1){
			//cout<<m<<" "<<8<<endl;
			n=(n+7)/8;
			c++;
		}
		n=8;
		m=8;
	}
	if(n>4){
       while(n>1){
			//cout<<m<<" "<<4<<endl;
			n=(n+3)/4;
			c++;
		}
		n=4;
		m=4;
	}
	while(n>1){
		//cout<<m<<" "<<2<<endl;
			n=(n+1)/2;
			c++;
	}
    cout<<c<<endl;
    n=N;
    m=n;
	for(int i=n;i>=2;i--){
		if(i!=2 && i!=4 && i!=8 && i!=n){
			cout<<i<<" "<<n<<endl;
		}
	}

	
	if(n>8){
		while(n>1){
			cout<<m<<" "<<8<<endl;
			n=(n+7)/8;
		}
		n=8;
		m=8;
	}
	if(n>4){
       while(n>1){
			cout<<m<<" "<<4<<endl;
			n=(n+3)/4;
		}
		n=4;
		m=4;
	}
	while(n>1){
		cout<<m<<" "<<2<<endl;
			n=(n+1)/2;
	}
}




int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}