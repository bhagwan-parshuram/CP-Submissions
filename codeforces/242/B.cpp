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
    int l[n+1];
    int r[n+1];
    int length=0;
    int index=-1;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=1;i<=n;i++){
    	cin>>l[i]>>r[i];
    	mini=min(mini,l[i]);
    	maxi=max(maxi,r[i]);
    	int curr=r[i]-l[i];
    	if(curr>=length){
    		index=i;
    		length=curr;
    	}
    }
    if(mini==l[index] && maxi==r[index]){
    	cout<<index<<endl;
    }
    else cout<<-1<<endl;

		
}