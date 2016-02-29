#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct point{
	int x,y;
}p[201];

int main() {
	int n,i,j,k,t;
	double map[201][201];
	for (t=1;cin>>n,n;t++) {
		for (i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n;j++)
				map[i][j]=map[j][i]=hypot(p[i].x-p[j].x,p[i].y-p[j].y);
		for (k=1;k<=n;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					map[i][j]=min(map[i][j],max(map[i][k],map[k][j]));
		cout<<"Scenario #"<<t<<endl<<"Frog Distance = "<<fixed<<setprecision(3)<<map[1][2]<<endl<<endl;
	}
}