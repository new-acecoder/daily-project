#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
void sovle()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>map(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    if(map[0][0]==map[n-1][m-1]||map[0][m-1]==map[n-1][0]){
        cout<<"YES"<<endl;
    }
    else{
        int w=0,b=0;
        for(int i=0;i<n;i++){
            if(map[i][0]=='W'){
                w++;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(map[i][m-1]=='W'){
                w++;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(map[0][i]=='W'){
                w++;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(map[n-1][i]=='W'){
                w++;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(map[i][0]=='B'){
                b++;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(map[i][m-1]=='B'){
                b++;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(map[0][i]=='B'){
                b++;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(map[n-1][i]=='B'){
                b++;
                break;
            }
        }
        if(w==4||b==4){
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sovle();
    }
    return 0;
}