#include <iostream>
using namespace std;

int main() {
	bool ox[9][9];
	char ch;
	int a[9][9],x[65],y[65],i,j,k,m,n,rx[8]={1,2,2,1,-1,-2,-2,-1},ry[8]={2,1,-1,-2,-2,-1,1,2};
	while (cin>>ch>>i) {
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(a,0,sizeof(a));
		memset(ox,1,sizeof(ox));
		cout<<"To get from "<<ch<<i;
		x[1]=ch-96,y[1]=i;
		ox[x[1]][y[1]]=0;
		cin>>ch>>j;
		cout<<" to "<<ch<<j;
		i=ch-96;
		m=1,n=2;
		while ((x[m]!=i||y[m]!=j)&&ox[i][j]) {
			for (k=0;k<8;k++) {
				if (ox[x[m]+rx[k]][y[m]+ry[k]]&&x[m]+rx[k]<=8&&y[m]+ry[k]<=8&&x[m]+rx[k]>0&&y[m]+ry[k]>0) {
					a[x[m]+rx[k]][y[m]+ry[k]]=a[x[m]][y[m]]+1;
					ox[x[m]+rx[k]][y[m]+ry[k]]=0;
					if (x[m]+rx[k]==i&&y[m]+ry[k]==j) {
						ox[i][j]=0;
						break;
					}
					else {
						x[n]=x[m]+rx[k],y[n]=y[m]+ry[k];
						n++;
					}
				}
			}
			m++;
		}
		cout<<" takes "<<a[i][j]<<" knight moves.\n";
	}
}