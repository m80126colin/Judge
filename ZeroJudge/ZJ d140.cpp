#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double n;
	while (cin>>n) {
		if (n<=100.00) n=n*0.9+8;
		else if (n<=500.00) n=n*0.8;
		else n=n*0.6;
		n+=0.0005;
		n=floor(n*100);
		n/=100;
		cout<<fixed<<setprecision(2)<<'$'<<n<<endl;
	}
}