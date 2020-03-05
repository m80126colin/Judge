#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,t;
	while (cin>>n&&n) {
		t=sqrt((double) n)+1e-12;
		cout<<( (t*t==n) ? "yes" : "no" )<<endl;
	}
}