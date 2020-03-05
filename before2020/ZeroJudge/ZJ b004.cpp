#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double d,l;
	while (cin>>d>>l) cout<<fixed<<setprecision(3)<<pow(((l*l-d*d)/4.0),0.5)*(l/2.0)*2.0*acos(0.0)<<endl;
}