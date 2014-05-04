#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double d,v,s;
	while (cin>>d>>v&&d&&v) {
		s=pow(pow(d,3)-3.0*v/acos(0.0),(double) 1/3);
		cout<<fixed<<setprecision(3)<<s<<endl;
	}
}