#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<1<<" "<<1<<endl;
			cout<<1<<" "<<1<<" "<<1<<endl;
		}
		else{
			int sum=n*(n+1)*(4*n-1)/6;
			cout<<sum<<" "<<2*n-1<<endl;
			for(int i=1;i<=n;i++){
				cout<<1<<" "<<i<<" ";
				for(int j=1;j<=n;j++){
					cout<<j<<" ";
				}
				cout<<endl;
			}
			for(int i=1;i<n;i++){
				printf("2 %d ",i);
				for(int j=1;j<=n;j++){
					printf("%d ",j);
				}
				cout<<endl;
			}
			printf("\n");
		}

	}
	return 0;
}
/*
0 0 0
0 0 0
0 0 0



1 2 3
2 2 3
3 3 3

1 2 3 4 an=(2n-1)n+an-1
2 2 3 4
3 3 3 4
4 4 4 4

1 2 3 4 5
2 2 3 4 5
3 3 3 4 5
4 4 4 4 5
5 5 5 5 5 */