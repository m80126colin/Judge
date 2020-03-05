#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double t;
	int a,b;
	while (scanf("%d:%d",&a,&b)&&(a||b)) {
		t=abs((double) a*30-b*6+b/2.0);
		cout<<fixed<<setprecision(3)<<abs(t-360*(180<t))<<endl;
	}
}