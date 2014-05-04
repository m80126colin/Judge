#include <iostream>
#include <string>
using namespace std;

bool map[6][6];

void backtracking(int x,int y,string s) {
	int i,j;
	char ch;
	bool z[6][6];
	if (x==8) {
		cout<<s<<endl;
		return;
	}
	for (i=1;i<=5;i++) {
		for (j=1;j<=5;j++) z[i][j]=map[i][j];
	}
	for (i=1;i<=5;i++) {
		if (z[y][i]) {
			z[y][i]=z[i][y]=0;
			ch=i+'0';
			map[y][i]=map[i][y]=0;
			backtracking(x+1,i,s+ch);
			map[y][i]=map[i][y]=1;
		}
	}
	return;
}

int main() {
	map[1][2]=map[2][1]=map[1][3]=map[3][1]=map[1][5]=map[5][1]=1;
	map[2][3]=map[3][2]=map[2][5]=map[5][2]=1;
	map[3][4]=map[4][3]=map[3][5]=map[5][3]=map[4][5]=map[5][4]=1;
	backtracking(0,1,"1");
}