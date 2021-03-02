
#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define ll long long
void solve(){
    int n;
    cin >> n;
    ll a[n + 1];
    rep(i,0,n) cin >> a[i];
    ll ans = 0;
    ll temp[n + 1];
    rep(i, 0, n) temp[i] = 0;

    rep(i,0,n){
        int curr = temp[i];
        if(curr+1<a[i]){
            ans += (a[i]-curr-1);
            curr = a[i] - 1;
        }

        temp[i + 1] += (curr + 1 - a[i]);
        for (int j = i + 2;( j <= i + a[i])&&(j<n);j++)
            temp[j]++;
    }
    cout << ans << endl;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
		
}