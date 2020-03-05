#include <iostream>
#include <string>
using namespace std;

bool A[100][101];

void matrix() {
	int i,j;
	memset(A,0,sizeof(A));
	A[0][0]=A[0][1]=A[0][10*1+0]=1;
	A[9][9]=A[9][8]=A[9][10*1+9]=1;
	A[10*9+0][10*9+0]=A[10*9+0][10*9+1]=A[10*9+0][10*8+0]=1;
	A[10*9+9][10*9+9]=A[10*9+9][10*9+8]=A[10*9+9][10*8+9]=1;
	for (j=1;j<10-1;j++) {
		A[j][j]=A[j][j-1]=A[j][j+1]=A[j][j+10]=1;
		A[90+j][90+j]=A[90+j][90+j-1]=A[90+j][90+j+1]=A[90+j][90+j-10]=1;
		A[10*j][10*j]=A[10*j][10*(j-1)]=A[10*j][10*(j+1)]=A[10*j][10*j+1]=1;
		A[10*j+9][10*j+9]=A[10*j+9][10*(j-1)+9]=A[10*j+9][10*(j+1)+9]=A[10*j+9][10*j+8]=1;
	}
	for (i=1;i<10-1;i++) {
		for (j=1;j<10-1;j++) A[10*i+j][10*i+j]=A[10*i+j][10*i+j-1]=A[10*i+j][10*i+j+1]=A[10*i+j][10*(i-1)+j]=A[10*i+j][10*(i+1)+j]=1;
	}
}

int main() {
	int i,j,k;
	string s[10],t;
	while (cin>>t,t!="end") {
		matrix();
		for (i=0;i<10;i++) cin>>s[i];
		for (i=0;i<10;i++) for (j=0;j<10;j++) A[10*i+j][100]=((s[i][j]=='#') ? 0:1);
		for (i=0;i<100;i++) {
			if (!A[i][i]) {
				for (j=i+1;j<101;j++) {
					if (A[j][i]) for (k=0;k<101;k++) A[j][k]^=A[i][k]^=A[j][k]^=A[i][k];
				}
			}
			for (j=i+1;j<101;j++) {
				if (A[j][i]) for (k=0;k<101;k++) A[j][k]^=A[i][k];
			}
		}
		for (i=99-1;i>=0;i--) {
			for (j=i+1;j<101;j++) {
				if (A[i][j]) A[i][100]^=A[j][100];
			}
		}
		k=0;
		for (i=0;i<101;i++) k+=A[i][100];
		cout<<t<<" "<<k<<endl;
	}
}