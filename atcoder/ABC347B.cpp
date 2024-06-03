#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,int>m;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
    	string s2;
    	for(int j=i;j<s.size();j++){
    		s2.push_back(s[j]);
    		if(m[s2]==0){
    			ans++;
    			m[s2]=1;
    		}
    	}
    }
    cout<<ans;
    return 0;
}
