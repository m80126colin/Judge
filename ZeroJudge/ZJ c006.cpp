#include <iostream>
using namespace std;

int main() {
	int a[4],i;
	while (cin>>a[0]>>a[1]>>a[2]>>a[3]&&(a[0]||a[1]||a[2]||a[3])) {
		a[0]=a[0]-a[1];
		a[1]=a[2]-a[1];
		a[2]=a[2]-a[3];
		for (i=0;i<3;i++) {
			if (a[i]<0) a[i]+=40;
		}
		cout<<1080+(a[0]+a[1]+a[2])*9<<endl;
	}
}