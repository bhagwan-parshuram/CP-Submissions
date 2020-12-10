#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
using lli = long long;
#define Max 100005
#define mod 1000000007
#define  F first 
#define  S  second 
#define  pb push_back


bool fun(lli sum1,lli sum2,vector<int> s1,vector<int> s2,int a){
  if(sum1!=sum2) return sum1>sum2;
  if(s1!=s2) return s1>s2;
  return a;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int n; cin>>n;
    lli sum1=0;
    vector<int> s1,s2;
    lli sum2=0;
    int key;
    for(int i=0;i<n;i++){
    	lli a;cin>>a;
    	if(i==(n-1) && a>0) key=1;
    	if(i==(n-1) && a<0) key=0;

    	if(a>0) {
    		sum1+=a;
    		s1.push_back(a);
    	}
    	if(a<0){
    		a*=-1;
    		sum2+=a;
    		s2.push_back(a);
    	}
    }
    if(fun(sum1,sum2,s1,s2,key)) cout<<"first"<<endl;
    else cout<<"second"<<endl;



		
}