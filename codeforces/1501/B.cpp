
#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int ans[n];
        for (int i = 0; i < n;i++)
            cin >> a[i];
        memset(ans, 0, sizeof(ans));
        for (int i = n-1; i>=0;i--){
            int curr = a[i];
            while(curr-- && i>=0){
                ans[i] = 1;
                i--;
                if (i >= 0)
                    curr = max(curr, a[i]);
           }
        }
        for (int i = 0; i < n;i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}