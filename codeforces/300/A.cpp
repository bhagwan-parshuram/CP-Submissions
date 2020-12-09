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
	
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    lli n; cin>>n;
    int a[n],b[n],c[n];
    int j=0,k=0,p=0;
    int count=0;
    for(int i=0;i<n;i++){
    	int input;
    	cin>>input;

    	if(input<0) count++;
    	if(input<0 && j==0) a[j++]=input;
    	else if(input==0) b[k++]=0;
    	else {
    		c[p++]=input;

    	}
    }
    if((count&1)==0){
    	for(int i=0;i<p;i++) {
    		if(c[i]<0){
    			b[k++]=c[i];
    			for(int ptr=i;ptr<p-1;ptr++){
    				c[ptr]=c[ptr+1];
    			}
    		 p--;
    		 break;
    		}
    	}
    }

    cout<<1<<" "<<a[0]<<endl;
   
    cout<<p<<" ";
    for(int m=0;m<p;m++) cout<<c[m]<<" ";
    cout<<endl;

    cout<<k<<" ";
    for(int m=0;m<k;m++) cout<<b[m]<<" ";
    cout<<endl;

    



		
}