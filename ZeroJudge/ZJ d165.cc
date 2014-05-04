#include <iostream>
using namespace std;

int a[101][101],n,m;

int spilt(int i,int j) {
	int s=a[i][j];
	a[i][j]=0;
	if (j-1&&a[i][j-1]) s+=spilt(i,j-1);
	if (j+1<=m&&a[i][j+1]) s+=spilt(i,j+1);
	if (i-1&&a[i-1][j]) s+=spilt(i-1,j);
	if (i+1<=n&&a[i+1][j]) s+=spilt(i+1,j);
	return s;
}

int main() {
	int i,j,t,b;
	while (cin>>n>>m) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++)  scanf("%d",&a[i][j]);
		}
		for (t=b=0,i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (a[i][j]) t++,b=max(spilt(i,j),b);
			}
		}
		cout<<t<<endl<<b<<endl;
	}
}