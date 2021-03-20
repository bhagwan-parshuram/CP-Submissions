#include<bits/stdc++.h>
using namespace std;
#define MAX 200001
#define ll long long
int a[MAX];
int n, k;
bool check(int mid){
    ll b[n +1];
    b[0] = 0;
    for (int i = 0; i < n;i++){
        if(a[i]<mid)
            b[i+1] = -1;
        else
            b[i+1] = 1;
        b[i + 1] += b[i];
    }
    ll mini = LLONG_MAX;
    for (int j = 0; j + k <= n;j++){
        mini = min(mini, b[j]);
        if(b[j+k]-mini>0)
            return 1;
    }
    return 0;
}
int main(){
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int lo = 1;
    int hi = n;
    int ans = 1;
    while(lo<=hi){
        int mid = (lo + hi) / 2;

        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}