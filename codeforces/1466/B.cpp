
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

	// int count=s.size();
	// vector<int> v;
	// for(auto x:s){
	// 	int curr=x.fr;
	// 	v.push_back(curr);
	// 	if(!s.count(curr+1)  && (s[curr]>1)) count++;
	// }
	// for(int i=v.size()-1;i>0;i--){
	// 	if((v[i]-1 == v[i-1]) && (s[v[i-1]]>1) && s[v[i]]==1 ){
	// 		count++;
	// 		//cout<<"Pv"<<v[i]<<" ";
	// 	}
	// }
   //cout<<endl;

	//cout<<count<<endl;
}



int main()
{
	fast;
    int t; cin>>t;
    while(t--) {
    	int n;
	cin>>n;
	int a[n];
	int maxi=INT_MIN;
	
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}
	vector<int>s(maxi+2);
	vector<int>p(maxi+2);
	for(int i=1;i<=maxi+1;i++){
		s[i]=0;
		p[i]=0;
	}
	for(int i=0;i<n;i++){
		s[a[i]]++;
	}

	int prev=1;
	// for(auto &x: s){
	// 	int curr=x.fr;
	// 	int c=x.sc;
	// 	s[curr]-=(c-1-prev);
	// 	s[curr+1]+=(c-1-prev);
	// 	prev=c-1;
	// }
	int ans=0;
	for(int i=1;i<=maxi+1;i++){
		if(p[i]>0){
			p[i+1]+=s[i];
		}
		else if(s[i]>1){
			p[i+1]+=(s[i]-1);
		}
		if(s[i]>=1 || p[i]>0)ans++;
	}
	
	cout<<ans<<endl;
    }
		
}