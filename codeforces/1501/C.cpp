
#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"
pair<int, int> mp[5000003];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int curr = a[i] + a[j];
            if (mp[curr] != make_pair(0, 0))
            {
                auto cur = mp[curr];
                int ind1 = cur.first;
                int ind2 = cur.second;
                if (i != ind1 && j != ind2 && i != ind2 && j != ind1)
                {
                    cout << "YES" << endl;
                    cout << i + 1 << " " << j + 1 << " " << ind1+1 << " " << ind2+1 << endl;
                    return 0;
                }
            }
            mp[curr] = {i, j};
        }
            
         }
        cout << "NO" << endl;
}
