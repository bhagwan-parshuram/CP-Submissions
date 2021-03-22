#include<bits/stdc++.h>
using namespace std;



//=============================================================================

int cnt[100005];
int ans[100005];
int taken[100005];

bool compare(vector<int> v1,vector<int> v2){
    return int(v1.size()) < int(v2.size());
}
bool compare2(int x,int y) {
    return cnt[x] < cnt[y];
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m+1);
    int lim = (m + 1) / 2;
    memset(cnt, 0, sizeof(cnt));
    memset(taken, 0, sizeof(taken));
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <=m;i++){
        int y;
        cin >> y;
        int x;
        for (int j = 1; j <= y;j++){
            cin >> x;
            v[i].push_back(x);
            cnt[x]++;
        }
        v[i].push_back(i);
        }
        

        sort(v.begin()+1, v.end(),compare);
        for (int i = 1; i <= m;i++){
            int sz = v[i].size() - 1;
            if(sz==0){
                 cout << "NO" << endl;
                return;
            }
            int day = v[i][sz];
            sort(v[i].begin(), v[i].end()-1, compare2);
            int p = 0;
            while(p<sz && taken[v[i][p]]>=lim)
                p++;
            if(p>=sz){
                cout << "NO" << endl;
                return;
            }
            else{
                //debug(v[i][sz], m);
                //cout << "p:" << p << endl;
                ans[v[i][sz]] = v[i][p];
                taken[v[i][p]]++;
            }
        }
        cout << "YES" << endl;
        for (int i = 1; i <= m;i++)
            cout << ans[i] << " ";
        cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}





//=============================================================================




