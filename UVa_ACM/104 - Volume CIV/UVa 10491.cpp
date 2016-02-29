#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double p;
	int cow,car,door;
	while (cin>>cow>>car>>door) {
		p=(double) ((cow+car-1)*car)/((cow+car)*(cow+car-door-1));
		cout<<fixed<<setprecision(5)<<p<<endl;
	}
}