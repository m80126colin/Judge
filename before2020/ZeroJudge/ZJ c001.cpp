#include <iostream>
#include <string>
using namespace std;

int main() {
	string m,n;
	static int i,j,k[1001][1001];
	while (getline(cin,m)&&getline(cin,n)) {
		for (i=0;i<=m.size();i++) k[i][0]=0;
		for (j=0;j<=n.size();j++) k[0][j]=0;
		for (i=1;i<=m.size();i++) {
			for (j=1;j<=n.size();j++) {
				if (m[i-1]==n[j-1]) k[i][j]=k[i-1][j-1]+1;
				else k[i][j]=max(k[i-1][j],k[i][j-1]);
			}
		}
		cout<<k[m.size()][n.size()]<<endl;
	}
}