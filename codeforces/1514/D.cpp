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
long long arr[300005];
vvi v;
ll count(int l,int r,int val){
    return upper_bound(v[val].begin(),v[val].end(),r)-lower_bound(v[val].begin(),v[val].end(),l);
}
struct node{//check
  long long val;
  node(long long a=-1){
    val=a;
  }
};
node  tree[1200020];

node merge(int l,int r,node A,node B){/*checck*/
   node res=B;
   if(count(l,r,A.val)>count(l,r,B.val)){
    res=A;
   }
   return res;

}
void build(int index,int l,int r){
   if(l==r){
       tree[index] = arr[l];
       return;
   }
   int mid = (l + r) / 2;
   build( 2 * index, l, mid);
   build( 2 * index + 1, mid + 1, r);

   tree[index] = merge(l,r,tree[2*index],tree[2*index+1]);//to be modified
}
void update(int index,int l,int r,int pos,int val){
  if(pos<l || pos>r) return;
  if(l==r) {
    arr[l]+=val;
    tree[index]=node(arr[l])/*checck*/;
    return; 
  }

  int mid=(l+r)/2;
  update(2*index,l,mid,pos,val);
  update(2*index+1,mid+1,r,pos,val);
  tree[index]=merge(l,r,tree[2*index],tree[2*index+1]);
}

node query(int index,int l,int r,int lq,int rq){
  if(rq<l || r<lq) return node(0);/*checck*/
  if(lq<=l && rq>=r){
    return tree[index];
  }

  int mid=(l+r)/2;
  return merge(lq,rq,query(2*index,l,mid,lq,rq),query(2*index+1,mid+1,r,lq,rq));
  //always start indexing from 1
}
//build(index=1,l=1,r=n)
//update(index=1,l=1,r=n,pos,val)
//query(index=1,l=1,r=1,lq,rq)
//always check the merge function

void solve(){
  ll n,q;
  cin>>n>>q;
  v.resize(3*100001);
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    v[arr[i]].pb(i);
  }
  build(1,1,n);
  while(q--){
    int l,r;
    cin>>l>>r;
    node res=query(1,1,n,l,r);
    //cout<<res.val<<" "<<endl;
    cout<<max(2*count(l,r,res.val)-(r-l+1),1LL)<<endl;
  }
}

int main(){
  fast;
  int t=1;
  while(t--)
    solve();
}
