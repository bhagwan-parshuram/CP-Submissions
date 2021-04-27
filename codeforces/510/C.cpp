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
int n;
vvi g;
bool visited[29];
int par[29];
vi topo;
map<int,char>mp;
set<int> recur;
bool cycle(int node,int p){
	visited[node]=1;
	par[node]=p;
	recur.insert(node);
    
    bool ans=0;
	for(auto u:g[node]){
		if(!visited[u]){
			ans=(ans || cycle(u,node));
		}
		else{
			if(recur.count(u))
			 ans=1;
			//cout<<mp[node]<<" "<<mp[u]<<endl;
		}
	}
	recur.erase(node);
	return ans;
}
void dfs(int node){
	visited[node]=1;
	for(auto u:g[node]){
		if(!visited[u]){
			dfs(u);
		}
	}
	topo.pb(node);
}
void solve(){
	g.clear();
	g.resize(27);
	cin>>n;
	string s[n+1];
	int m=n+1;
	string temp="abcdefghijklmnopqrstuvwxyz";
	for(auto c:temp){
		mp[c-'a']=c;
	}
	for(int i=0;i<n;i++){
		cin>>s[i];
		m=min(m,(int)s[i].size());

	}
	int p1=1;
	bool key=1;
	while(p1<n){
		int i;
		for(i=0;i<min(s[p1].size(),s[p1-1].size());i++){
			if(s[p1][i]!=s[p1-1][i]){
				g[s[p1][i]-'a'].pb(s[p1-1][i]-'a');
				//cout<<s[p1-1][i]<<" "<<s[p1][i]<<endl;
				break;
			}
		}
		if(i==min(s[p1].size(),s[p1-1].size()) && s[p1].size()<s[p1-1].size()){
			key=0;
			//cout<<s[p1]<<" "<<s[p1-1]<<endl;
		}
		p1++;
	}
	bool ans=0;
	for(int i=0;i<26;i++){
		memset(visited,0,sizeof(visited));
        if(cycle(i,-1)){
        	ans=1;
        	break;
        }
	}
	memset(visited,0,sizeof(visited));
	if(ans || (key==0)){
       cout<<"Impossible"<<endl;
	}
	else {
		for(int i=0;i<26;i++){
		if(!visited[i])dfs(i);
	 }
	 for(int i=0;i<topo.size();i++)cout<<mp[topo[i]];
	 cout<<endl;
	}


}

int main(){
	fast;
	int t=1;
	while(t--)
	  solve();
}
