#include <iostream>
using namespace std;

int main() {
	int i,j,a[100][100];
	while (cin>>i>>j) {
		for (a[0][1]=1;a[0][1]<=i;a[0][1]++) {
			for (a[1][0]=1;a[1][0]<=j;a[1][0]++) cin>>a[a[0][1]][a[1][0]];
		}
		for (a[0][1]=1;a[0][1]<=j;a[0][1]++) {
			for (a[1][0]=1;a[1][0]<=i;a[1][0]++) {
				cout<<a[a[1][0]][a[0][1]];
				if (a[1][0]!=i) cout<<" ";
			}
			cout<<endl;
		}
	}
}