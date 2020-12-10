#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
using lli = long long;
#define Max 100005
#define mod 1000000007
#define  F first 
#define  S  second 
#define  pb push_back




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int n; cin>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++) {
    	cin>>a[i];
    	if(a[i]==i) ans++;
	}
	if(ans<n){
		ans++;
	for(int i=0;i<n;i++){
		if(a[i]!=i  && a[a[i]]==i){
			ans++;
			break;
		}
	}
	}
	
	cout<<ans<<endl;
}