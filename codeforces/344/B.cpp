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
    int a,b,c;
    cin>>a>>b>>c;
    lli sum1=(b+a-c);
    lli sum2=(b+c-a);
    lli sum3=(a+c-b);

    if(((sum1%2==0)&&sum1>=0)  && ((sum2%2==0)&&sum2>=0) && ((sum3%2==0)&&sum3>=0)){
    	cout<<sum1/2<<" "<<sum2/2<<" "<<sum3/2<<endl;

    }
    else {
    	cout<<"Impossible"<<endl;
    }
		
}