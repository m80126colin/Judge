#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int main() {
	static long long a[801][201],n,i,j,k,con;
	for (con=i=1;i<=10;i++) con*=10;
	memset(a,0,sizeof(a));
	a[2][1]=1;
	for (i=3;i<=800;i++) {
		k=0;
		for (j=1;j<201;j++) {
			if (k) a[i][j]+=k,k=0;
			a[i][j]+=(i-1)*(a[i-1][j]+a[i-2][j]);
			if (a[i][j]/con) k=a[i][j]/con,a[i][j]%=con;
		}
	}
	while (cin>>n&&n>0) {
		bool ox;
		ox=0;
		for (j=200;j;j--) {
			if (ox) cout<<setw(10)<<setfill('0')<<a[n][j];
			else if (a[n][j]) ox=1,cout<<a[n][j];
		}
		if (!ox) cout<<0;
		cout<<endl;
	}
}