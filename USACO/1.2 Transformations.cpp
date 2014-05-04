/*
ID: m80126c2
PROG: transform
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream cin("transform.in");
ofstream cout("transform.out");

int n,t;
char ch[11][11],ref[11][11],re2[11][11];

bool ismatch() {
	int i,j;
	bool ox=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (re2[i][j]!=ref[i][j]) ox=0;
		}
	}
	return ox;
}

bool re() {
	int i,j;
	char re[11][11];
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) re[i][j]=re2[i][j];
	}
	for (t=1;t<=3;t++) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) re2[j][n+1-i]=re[i][j];
		}
		if (ismatch()) return 1;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) re[i][j]=re2[i][j];
		}
	}
	return 0;
}

bool refle() {
	int i,j;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) re2[i][n+1-j]=ch[i][j];
	}
	if (ismatch()) return 1;
	else return 0;
}

bool comb() {
	if (re()) return 1;
	else return 0;
}

bool even() {
	int i,j;
	bool ox=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (ch[i][j]!=ref[i][j]) ox=0;
		}
	}
	return ox;
}

int main() {
	int i,j;
	cin>>n;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) cin>>ch[i][j],re2[i][j]=ch[i][j];
	}
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) cin>>ref[i][j];
	}
	if (re()) cout<<t<<endl;
	else if (refle()) cout<<4<<endl;
	else if (comb()) cout<<5<<endl;
	else if (even()) cout<<6<<endl;
	else cout<<7<<endl;
}