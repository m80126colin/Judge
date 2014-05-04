#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a,b,c,h,m;
	cout<<showpoint<<fixed;
	cin>>h;
	cin.ignore(1);
	cin>>m;
	while (h||m) {
		a=30*h+m/2;
		b=6*m;
		if (a>=b) c=a-b;
		else c=b-a;
		if (c>180) c=360-c;
		cout<<setprecision(3)<<c<<endl;
		cin>>h;
		cin.ignore(1);
		cin>>m;
	}
}