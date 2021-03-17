
#include<bits/stdc++.h>
using namespace std; 
#define endl "\n"


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n + 1], b[n + 1];
        for (long long i = 0; i < n;i++){
            cin >> a[i] >> b[i];
        }
        long long tm[n];
        for (long long i = 0; i < n;i++){
            cin >> tm[i];
            if(i)
                tm[i] += a[i] - b[i - 1];
            else
                tm[i] += a[i];
        }
            
        long long curr = 0;
        for (long long i = 0; i < n;i++){
            curr += tm[i];
            if(i==n-1)
                continue;
            long long interval = b[i] - a[i];
            long long k = (interval + 1) / 2;
            if(curr+k<=b[i])
                curr = b[i];
            else
                curr += k;
            
        }
        cout << curr << endl;
    }
}