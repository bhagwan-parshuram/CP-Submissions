#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int p1 = 0;
    int p2 = 0;
    int ans = 0;
    vector<int> l, r;
    while (p1 < n && p2 < m){
        if(s[p1]==t[p2]){
            l.pb(p1);
            p2++;
        }
        p1++;
    }
    p1 = n - 1;
    p2 = m - 1;
    while(p1>=0 && p2>=0){
        if(s[p1]==t[p2]){
            r.pb(p1);
            p2--;
        }
        p1--;
    }
    reverse(r.begin(), r.end());
    for (int i = 1; i < m;i++){
        ans = max(ans, r[i] - l[i - 1]);
    }
        cout << ans << endl;
}