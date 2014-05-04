#include <iostream>
using namespace std;

int main() {
	bool a[3],b[3];
	int n,i[4],j[4];
	while (cin>>n>>i[1]>>i[2]>>i[3]>>j[1]>>j[2]>>j[3]&&n) {
		for (i[0]=0;i[0]<3;i[0]++) a[i[0]]=b[i[0]]=0;
		for (i[0]=1;i[0]<=3;i[0]++) {
			for (j[0]=1;j[0]<=3;j[0]++) {
				if ((i[i[0]]==j[j[0]]||n-i[i[0]]==j[j[0]])&&a[i[0]-1]==0&&b[j[0]-1]==0) {
					a[i[0]-1]=b[j[0]-1]=1;
					break;
				}
			}
		}
		if (a[0]==1&&a[1]==1&&a[2]==1&&b[0]==1&&b[1]==1&&b[2]==1) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}