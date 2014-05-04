#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double f,r;
	cout<<showpoint<<fixed;
	while (cin>>f) {
		r =  sin((double)atan((double)1)*8/5)*f/sin((double)atan((double)1)*63/45);
		cout<<setprecision(10)<<r<<endl;
	}
}