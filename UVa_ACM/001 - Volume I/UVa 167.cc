#include <iostream>
#include <iomanip>
using namespace std;

int k,t,a[9][9];

int main() {
	int i,j;
	int q[92][8] = {{1,5,8,6,3,7,2,4},{1,6,8,3,7,4,2,5},{1,7,4,6,8,2,5,3},{1,7,5,8,2,4,6,3},{2,4,6,8,3,1,7,5},{2,5,7,1,3,8,6,4},{2,5,7,4,1,8,6,3},{2,6,1,7,4,8,3,5},
               {2,6,8,3,1,4,7,5},{2,7,3,6,8,5,1,4},{2,7,5,8,1,4,6,3},{2,8,6,1,3,5,7,4},{3,1,7,5,8,2,4,6},{3,5,2,8,1,7,4,6},{3,5,2,8,6,4,7,1},{3,5,7,1,4,2,8,6},
               {3,5,8,4,1,7,2,6},{3,6,2,5,8,1,7,4},{3,6,2,7,1,4,8,5},{3,6,2,7,5,1,8,4},{3,6,4,1,8,5,7,2},{3,6,4,2,8,5,7,1},{3,6,8,1,4,7,5,2},{3,6,8,1,5,7,2,4},
               {3,6,8,2,4,1,7,5},{3,7,2,8,5,1,4,6},{3,7,2,8,6,4,1,5},{3,8,4,7,1,6,2,5},{4,1,5,8,2,7,3,6},{4,1,5,8,6,3,7,2},{4,2,5,8,6,1,3,7},{4,2,7,3,6,8,1,5},
               {4,2,7,3,6,8,5,1},{4,2,7,5,1,8,6,3},{4,2,8,5,7,1,3,6},{4,2,8,6,1,3,5,7},{4,6,1,5,2,8,3,7},{4,6,8,2,7,1,3,5},{4,6,8,3,1,7,5,2},{4,7,1,8,5,2,6,3},
               {4,7,3,8,2,5,1,6},{4,7,5,2,6,1,3,8},{4,7,5,3,1,6,8,2},{4,8,1,3,6,2,7,5},{4,8,1,5,7,2,6,3},{4,8,5,3,1,7,2,6},{5,1,4,6,8,2,7,3},{5,1,8,4,2,7,3,6},
               {5,1,8,6,3,7,2,4},{5,2,4,6,8,3,1,7},{5,2,4,7,3,8,6,1},{5,2,6,1,7,4,8,3},{5,2,8,1,4,7,3,6},{5,3,1,6,8,2,4,7},{5,3,1,7,2,8,6,4},{5,3,8,4,7,1,6,2},
               {5,7,1,3,8,6,4,2},{5,7,1,4,2,8,6,3},{5,7,2,4,8,1,3,6},{5,7,2,6,3,1,4,8},{5,7,2,6,3,1,8,4},{5,7,4,1,3,8,6,2},{5,8,4,1,3,6,2,7},{5,8,4,1,7,2,6,3},
               {6,1,5,2,8,3,7,4},{6,2,7,1,3,5,8,4},{6,2,7,1,4,8,5,3},{6,3,1,7,5,8,2,4},{6,3,1,8,4,2,7,5},{6,3,1,8,5,2,4,7},{6,3,5,7,1,4,2,8},{6,3,5,8,1,4,2,7},
               {6,3,7,2,4,8,1,5},{6,3,7,2,8,5,1,4},{6,3,7,4,1,8,2,5},{6,4,1,5,8,2,7,3},{6,4,2,8,5,7,1,3},{6,4,7,1,3,5,2,8},{6,4,7,1,8,2,5,3},{6,8,2,4,1,7,5,3},
               {7,1,3,8,6,4,2,5},{7,2,4,1,8,5,3,6},{7,2,6,3,1,4,8,5},{7,3,1,6,8,5,2,4},{7,3,8,2,5,1,6,4},{7,4,2,5,8,1,3,6},{7,4,2,8,6,1,3,5},{7,5,3,1,6,8,2,4},
               {8,2,4,1,7,5,3,6},{8,2,5,3,1,7,4,6},{8,3,1,6,2,5,7,4},{8,4,1,3,6,2,7,5}};
	for (cin>>k;k;k--) {
		memset(a,0,sizeof(a));
		for (i=1;i<=8;i++) {
			for (j=1;j<=8;j++) cin>>a[i][j];
		}
		t=0;
		for (i=0;i<92;i++) t=max(t,a[1][q[i][0]]+a[2][q[i][1]]+a[3][q[i][2]]+a[4][q[i][3]]+a[5][q[i][4]]+a[6][q[i][5]]+a[7][q[i][6]]+a[8][q[i][7]]);
		cout<<setw(5)<<t<<endl;
	}
}