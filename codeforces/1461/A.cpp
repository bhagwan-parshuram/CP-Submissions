#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
using lli = long long;
#define Max 100005
#define mod 1000000007
#define  F first 
#define  S  second 
#define  pb push_back


void solve(){
	int n,k;
	cin>>n>>k;
	int index=0;
	string s;
	while(index<n){
		for(int i=0;i<k;i++){
            s+='a';
            index++;
            if(index>=n) break;
		}
		if(index<n){
			for(int i=0;i<k;i++){
             s+='b';
            index++;
            if(index>=n) break;
		}
		}
		if(index<n){
			for(int i=0;i<k;i++){
             s+='c';
            index++;
            if(index>=n) break;
		}
		}
	}
	cout<<s<<endl;
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
		
}