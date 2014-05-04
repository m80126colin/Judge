#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	bool k[101][101];
	static int a,i,j,x,y,t,m[101][101];
	stringstream ss;
	string s;
	for (cin>>t;t;t--) {
		cin>>x>>y;
		for (i=0;i<=x;i++) m[i][0]=k[i][0]=0;
		for (j=0;j<=y;j++) m[0][j]=k[i][0]=0;
		for (i=1;i<=x;i++) {
			for (j=1;j<=y;j++) k[i][j]=1;
		}
		cin.ignore(1);
		for (a=1;a<=x;a++) {
			getline(cin,s);
			ss.clear();
			ss.str(s);
			ss>>i;
			while (ss>>j) k[i][j]=0;
		}
		
		for (i=1;i<=x;i++) {
			for (j=1;j<=y;j++) {
				if (k[i][j]) {
					if (k[i-1][j]&&k[i][j-1]) m[i][j]=m[i-1][j]+m[i][j-1];
					else m[i][j]=max(m[i-1][j],m[i][j-1]);
				}
				else m[i][j]=0;
				m[1][1]=1;
			}
		}
		cout<<m[x][y]<<endl;
		if (t!=1) cout<<endl;
	}
}