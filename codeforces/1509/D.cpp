#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<pll> vpll; 
 
#define endl '\n' 
#define fast std::ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair

void solve(){
int n;
cin>>n;
string s[3];
for(int i=0;i<3;i++)cin>>s[i];

for(int i=0;i<3;i++){
	for(int j=i+1;j<3;j++){
		int count[3][2];
		memset(count,0,sizeof(count));
		for(int k=0;k<2*n;k++){
			count[1][1]+=s[i][k]=='1';
			count[1][0]+=s[i][k]=='0';

			count[2][1]+=s[j][k]=='1';
			count[2][0]+=s[j][k]=='0';
			if(count[1][1]>=n && count[2][1]>=n){
				int sz=min(count[1][1],count[2][1]);
				int p1=0;
				int p2=0;
				while(sz--){
					int c1=0;
					int c2=0;
					while(s[i][p1]!='1'){
						c1++;
						p1++;
					}
					while(s[j][p2]!='1'){
						c2++;
						p2++;
					}
					int c=max(c1,c2);
					while(c--){
						cout<<0;
					}
					cout<<1;
					p1++;
					p2++;
				}
				while(p1<2*n)cout<<s[i][p1],p1++;
				while(p2<2*n)cout<<s[j][p2],p2++;
				cout<<endl;
				return;
			}
			if(count[1][0]>=n && count[2][0]>=n){
				int sz=min(count[1][0],count[2][0]);
				int p1=0;
				int p2=0;
				while(sz--){
					int c1=0;
					int c2=0;
					while(s[i][p1]!='0'){
						c1++;
						p1++;
					}
					while(s[j][p2]!='0'){
						c2++;
						p2++;
					}
					int c=max(c1,c2);
					while(c--){
						cout<<1;
					}
					cout<<0;
					p1++;
					p2++;
				}

				while(p1<2*n)cout<<s[i][p1],p1++;
				while(p2<2*n)cout<<s[j][p2],p2++;
				cout<<endl;
				return;
			}

		
		}
	}
 }	
}

int main(){
	fast;
	int t=1;
	cin>>t;
	while(t--)
	  solve();
}
