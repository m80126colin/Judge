#include <iostream>
using namespace std;

int main() {
	bool ox[3][3];
	int n,s,i,j;
	memset(ox,0,sizeof(ox));
	s=0;
	for (n=1;n<=9;n++) {
		cin>>i>>j;
		if (i>30||j>30||i<0||j<0||i%10==0||j%10==0) continue;
		i/=10,j/=10;
		if (ox[i][j]==0) {
			ox[i][j]=1;
			if (i==1&&j==1) s+=2;
			else if ((i==1&&j==0)||(i==2&&j==1)||(i==1&&j==2)||(i==0&&j==1)) s+=5;
			else s+=8;
		}
	}
	n=0;
	for (i=0;i<3;i++) {
		if (ox[i][0]&&ox[i][1]&&ox[i][2]) n++;
		if (ox[0][i]&&ox[1][i]&&ox[2][i]) n++;
	}
	cout<<n<<" "<<s<<endl;
}