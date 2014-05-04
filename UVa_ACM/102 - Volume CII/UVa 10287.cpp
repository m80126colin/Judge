#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double s,r1,r2,r3,r4;
	cout<<showpoint<<fixed;
	while (cin>>s) {
		r1 = (pow(3,0.5)/2)*s;
		r2 = (2*pow(3,0.5)-3)*s;
		r3 = (pow(3,0.5)/4)*s;
		r4 = (6*pow(7,0.5)-7*pow(3,0.5))*s/10;
		cout<<setprecision(10)<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;
	}
}