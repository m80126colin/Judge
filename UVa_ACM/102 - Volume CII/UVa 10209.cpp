#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	double a,x,y,z;
	cout<<showpoint<<fixed;
	while (cin>>a) {
		x=(1.0+2.0*acos(0.0)/3-pow(3,0.5))*a*a;
		y=(-4.0+2.0*acos(0.0)/3+pow(3,0.5)*2)*a*a;
		z=(4.0-4.0*acos(0.0)/3-pow(3,0.5))*a*a;
		cout<<setprecision(3)<<x<<" "<<y<<" "<<z<<endl;
	}
}