#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a,b,c;
	while (cin>>a>>b>>c) {
		c=b*b-4*a*c;
		if (c>0) cout<<"Two different roots x1="<<(-b+sqrt((double) c))/(2*a)<<" , x2="<<(-b-sqrt((double) c))/(2*a)<<endl;
		else if (c) cout<<"No real root"<<endl;
		else cout<<"Two same roots x="<<-b/2/a<<endl;
	}
}