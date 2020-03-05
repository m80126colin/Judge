#include <iostream>
#include <math.h>
using namespace std;

int main() {
	bool ox1,ox2;
	int a,b,x,y;
	while (cin>>a>>b&&a&&b) {
		ox1=1;ox2=0;
		x=sqrt((double) max(a*a,b*b)-min(a*a,b*b));
		y=max(a*a,b*b)-min(a*a,b*b);
		if (x*x==y) {
			cout<<x;
			ox1=0;
			ox2=1;
		}
		x=sqrt((double) max(a*a,b*b)+min(a*a,b*b));
		y=max(a*a,b*b)+min(a*a,b*b);
		if (x*x==y) {
			if (ox2) cout<<" ";
			cout<<x;
			ox1=0;
		}
		if (ox1) cout<<"Wrong";
		cout<<endl;
	}
}