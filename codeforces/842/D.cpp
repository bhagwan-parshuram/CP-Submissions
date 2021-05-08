#include<iostream>
using namespace std;
#define ll long long

ll n,m;
ll a[1000000];
struct node{
	ll count;
	node* child[2];
	node(){
		count=0;
		child[0]=nullptr;
		child[1]=nullptr;
	}
};
node *trie;

void insert(ll x){
	node* p=trie;
	for(ll i=30;i>=0;i--){
		ll u=((1LL<<i)&x)?1:0;
        for(ll j=0;j<2;j++){
        	if((p->child[j])==nullptr){
         	 node* curr=new node;
          	 p->child[j]=curr;
         	 }
        }
        p->child[u]->count++;
        p=p->child[u];
    }
}
ll dfs(ll x){
	node* p=trie;
	ll ans=0;
	for(int i=30;i>=0;i--){
		ll u=((1LL<<i)&x)?1:0;
		if(p->child[u]->count==0){
			ans+=(1LL<<i);
			p=p->child[1-u];
		}else
		p=p->child[u];
	}
	return ans;
}


int main(){
    cin>>n>>m;
    trie=new node;
        for(int i=0;i<n;i++){
    	ll x;
    	cin>>x;
        a[x]=1;
    }
    for(int i=0;i<=1000000;i++)if(!a[i])insert(i);
    ll val=0;
    while(m--){
    	ll x;
    	cin>>x;
    	val^=x;
    	ll ans=dfs(val);
    	cout<<ans<<endl;
    }

    
	return 0;
}