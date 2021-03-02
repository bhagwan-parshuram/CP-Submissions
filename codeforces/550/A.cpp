#include<bits/stdc++.h>
using namespace std;

bool isP(string s1, string &s2){
    int l = s1.size();
    int n = s2.size();
    for (int i = 0; i + l <=n;i++){
        if(s1==s2.substr(i,l)){
            s2 = (s2.substr(0, i) +"#"+ s2.substr(i + l, n - i - l));
           // cout << s2 << endl;
            return true;
        }
    }
    return false;
}

int main(){
    string s;
    cin >> s;

    string s2 = s;
    int k1= (isP("AB", s2) && isP("BA",s2));
    s2 = s;
    int k2= (isP("BA", s2) && isP("AB", s2));

    if(k1||k2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}