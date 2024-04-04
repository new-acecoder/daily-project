#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;    
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			for(int i=0;i<x;i++){
				cout<<"1"<<" ";
			}
		}
		else if(y==1){ 
			for(int i=1;i<=x;i++)
			{
				cout<<i<<" ";
			}
		}
		else{
			cout<<"-1";
		}
		cout<<endl;
	}
	return 0;
}