#include <iostream>
using namespace std;

bool ox;
int a[20]={1,2,3,4,5,6,7,8,9,153,370,371,407,1634,8208,9474,54748,92727,93084,548834};
int t,m,n;

int main() {
	while (cin>>n>>m) {
		ox=0;
		for (t=0;t<20;t++) {
			if (a[t]>=n&&a[t]<=m) {
				if (ox) cout<<" ";
				cout<<a[t];
				ox=1;
			}	
		}
		if (ox==0) cout<<"none";
		cout<<endl;
	}
}