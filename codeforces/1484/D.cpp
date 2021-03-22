#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

//linked list type implementation
int nxt[MAX];
int visited[MAX];
int a[MAX];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            nxt[i] = (i + 1)%n;
            visited[i] = 0;
        }
        for (int i = 0; i < n;i++){
            if(__gcd(a[i],a[nxt[i]])==1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr])
                continue;
            if(!visited[nxt[curr]]){
                ans.push_back(nxt[curr]);
                visited[nxt[curr]] = 1;
            }
            nxt[curr] = nxt[nxt[curr]];
            if(__gcd(a[curr],a[nxt[curr]])==1)
                    q.push(curr);
        }
        cout << ans.size() << " ";
        for (int i = 0; i < ans.size();i++)
            cout << ans[i] + 1 << " ";
        cout << endl;
    }
}