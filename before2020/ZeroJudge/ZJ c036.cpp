#include <iostream>
using namespace std;

int main() {
	double a,s,u;
	int h,d,f,t;
	while (cin>>h>>u>>d>>f&&h) {
		a=u*f/100;
		s=0;
		for (t=0;s<=h||s>=0;t++) {
			if (u>0) s+=u;
			if (s>h||s<=0) {
				t++;
				break;
			}
			s-=d;
			if (s<0) {
				t++;
				break;
			}
			u-=a;
		}
		if (s>=h) cout<<"success on day "<<t<<endl;
		if (s<=0) cout<<"failure on day "<<t<<endl;
	}
}