#include<bits/stdc++.h>
using namespace std;
int inf=1e7;
#define MAX 300005

struct node{
	int val;
	node(){
		val=inf;
	}
	void assign(int x){
		val=x;
	}

};
node tree[4*MAX];
vector<int> st[MAX];
node merge(node a,node b){
    node res;
    res.val=min(a.val,b.val);
    return res;
}

void update(int i,int l,int r,int pos,int x){
     if(pos <l || pos>r)return;//can reduce complexity
     if(l==r){
     	tree[i].assign(x);
     	return;
     }

     int  mid=(l+r)/2;
     if(pos<=mid)update(2*i,l,mid,pos,x);
     else update(2*i+1,mid+1,r,pos,x);
     tree[i]=merge(tree[2*i],tree[2*i+1]);
}

node query(int i,int l,int r,int lq,int rq){
	if(lq>r || rq<l){
		return node();
	}
	if(lq<=l && r<=rq){
		return tree[i];
	}
	int mid=(l+r)/2;
	return merge(query(2*i,l,mid,lq,rq),query(2*i+1,mid+1,r,lq,rq));
}
int n;
int a[MAX];
int b[MAX];
void solve(){
	cin>>n;
	for(int i=0;i<=n;i++){
		st[i].clear();
		st[i].resize(0);
	}
	for(int i=0;i<=4*n;i++){
		tree[i].val=inf;
	}

	for(int i=0;i<n;i++){
	  cin>>a[i];
	  a[i]--;
	  st[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		b[i]--;
	}
	for(int i=0;i<n;i++){
		reverse(st[i].begin(),st[i].end());
		if(!st[i].empty()){
	  	update(1,0,n-1,i,st[i].back());
	  }
	}
	for(int i=0;i<n;i++){
		int curr=b[i];
		if(st[curr].empty()){
			cout<<"NO"<<endl;
			return;
		}
		int pos=st[curr].back();
		node mini=query(1,0,n-1,0,curr);
		if(mini.val<pos){
            cout<<"NO"<<endl;
			return;
		}
		st[curr].pop_back();
		if(st[curr].empty()){
			update(1,0,n-1,curr,inf);
		}
		else update(1,0,n-1,curr,(st[curr].back()));
	}
    cout<<"YES"<<endl;
}

int main(){
 int t;
 cin>>t;
 while(t--){
 	solve();
 }
}