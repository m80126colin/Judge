#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long n,a,N;
	a=1;
	for (cin>>N;N;cin>>N) {
		n=sqrt((long double) (2*N)+2.25)+1.5;
		while (n*(n-3)<2*N) n++;
		cout<<"Case "<<a<<": "<<n<<endl;
		a++;
	}
}