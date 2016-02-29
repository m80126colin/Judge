#include <iostream>
using namespace std;

bool ox;
int n[10][10],i,j;

int in() {
	for (i=1;i<10;i++) {
		for (j=1;j<10;j++) {
			cin>>n[i][j];
			if (cin.eof()) return 0;
		}
	}
	return 1;
}

int check(int x,int y) {
	int a,b,c,d;
	for (a=x;a<x+3;a++) {
		for (b=y;b<y+3;b++) {
			for (c=a;c<x+3;c++) {
				for (d=y;d<y+3;d++) {
					if (n[a][b]==n[c][d]&&(a!=c&&b!=d)) {
						ox=0;
						i=j=10;
						break;
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	int a,b;
	while (in()) {
		ox=1;
		for (i=1;i<10;i+=3) {
			for (j=1;j<10;j+=3) check(i,j);
		}
		for (i=1;i<10;i++) {
			for (j=1;j<10;j++) {
				for (a=i+1;a<10;a++) {
					if (n[i][j]==n[a][j]) {
						ox=0;
						i=j=10;
						break;
					}
				}
				for (b=j+1;b<10;b++) {
					if (n[i][j]==n[i][b]) {
						ox=0;
						i=j=10;
						break;
					}
				}
			}
		}
		if (ox) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}