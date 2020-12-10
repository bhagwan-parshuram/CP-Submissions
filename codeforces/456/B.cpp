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
    string n;
    cin>>n;
    int dig1=n[n.size()-1]-'0';
    int dig2=0;
    if(n.size()>1){
        dig2=n[n.size()-2]-'0';
    }
    int num=10*dig2+dig1;
    if((num%4)==0) cout<<4<<endl;
    else cout<<0<<endl;
		
}