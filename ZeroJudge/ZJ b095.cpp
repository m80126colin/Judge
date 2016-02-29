#include <iostream>
using namespace std;

int main() {
	bool ox;
	int a,b,i,j,t;
	for (i=10;i;i--) {
		cin>>a>>b;
		a=max(a,b);
		ox=t=0;
		for (j=30;j;j--) {
			cin>>b;
			if (b==a&&t<3) ox=1;
			if (b&&ox==0&&b!=a) t++;
		}
		if (ox) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
}