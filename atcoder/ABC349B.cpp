#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    string s;
    cin >> s;
    map<char, int> hash;
    hash.clear();
    int maxn = 0;
    for(int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
        maxn = max(maxn, hash[s[i]]);
    }
    /*for(int i=0;i<s.size();i++){
        cout<<s[i]<<" "<<hash[s[i]]<<" "<<endl;
    }*/
    for(int i = 1; i <= maxn+1; i++) {
        for(int j = 0; j < s.size(); j++) {
            if(hash[s[j]] == i) {
                a[i]++;
            }
        }
    }
    /*for(int i=1;i<=maxn;i++){
        cout<<a[i]<<" "<<endl;
    }*/
    for(int i = 1; i <= maxn; i++) {
        if((a[i] != 2*i)&&a[i]!=0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
