#include <iostream>
using namespace std;

static int n1[101],n2[101],a[101][101],i,j,t;

int main() {
	for (t=1;cin>>n1[0]>>n2[0]&&n1[0]&&n2[0];t++) {
		a[0][0]=0;
		for (i=1;i<=n1[0];i++) {cin>>n1[i];a[i][0]=0;}
		for (j=1;j<=n2[0];j++) {cin>>n2[j];a[0][j]=0;}
		for (i=1;i<=n1[0];i++) {
			for (j=1;j<=n2[0];j++) {
				if (n1[i]==n2[j]) a[i][j]=a[i-1][j-1]+1;
				else a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		cout<<"Twin Towers #"<<t<<endl<<"Number of Tiles : "<<a[n1[0]][n2[0]]<<endl<<endl;
	}
}