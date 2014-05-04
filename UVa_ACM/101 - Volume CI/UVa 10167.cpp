#include <iostream>
using namespace std;

int main() {
	bool ox;
	int n,i,sx[101],sy[101];
	int a,b,pos,neg;
	while (cin>>n&&n) {
		for (i=1;i<=2*n;i++) cin>>sx[i]>>sy[i];
		for (a=-500;a<=500;a++) {
			for (b=-500;b<=500;b++) {
				ox=1;
				for (i=1,pos=neg=0;i<=2*n;i++) {
					if (a*sx[i]+b*sy[i]>0) pos++;
					else if (a*sx[i]+b*sy[i]<0) neg++;
					else {
						ox=0;
						break;
					}
				}
				if (ox&&pos==neg) {
					cout<<a<<" "<<b<<endl;
					a=b=1000;
				}
			}
		}
	}
}