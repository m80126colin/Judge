#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	int a,b;
	double c;
	cin>>a>>b;
	cout<<pow((double) a,b)<<endl;
	cin>>c;
	cout<<fixed<<setprecision(3)<<sqrt(c)<<endl;
	cin>>a;
	cout<<abs(a)<<endl;
	cin>>a>>b;
	cout<<a<<endl;
}