
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

bool regular(string s){
	int c=0;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='(') c++;
		else c--;
		if(c<0) return false;
	}
	return c==0;
}

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	int count=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='?') count++;
    }
	if(n%2){
		cout<<"NO"<<endl;
		return;
	}
	int half=count/2;
	int index=0;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			s[i]=index++<half?'(':')';
		}
	}
	if(regular(s))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) solve();
		
}
