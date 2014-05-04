#include <iostream>
using namespace std;

bool m[1001][1001];

int main() {
	char ch;
	int a,b,x,y,i,j;
	while (cin>>a>>b) {
		if (!(a&&b)) break;
		for (i=0;i<=a+1;i++) {
			for (j=0;j<=b+1;j++) m[i][j]=0;
		}
		for (i=1;i<=a;i++) {
			for (j=1;j<=b;j++) {
				cin>>ch;
				if (ch=='x') m[i][j]=1;
				else if (ch=='?') x=i,y=j;
			}
		}
		cout<<m[x-1][y-1]+m[x][y-1]+m[x+1][y-1]+m[x-1][y]+m[x+1][y]+m[x-1][y+1]+m[x][y+1]+m[x+1][y+1]<<endl;
	}
}