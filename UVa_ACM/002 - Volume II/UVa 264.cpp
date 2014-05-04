#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,a,b;
	while (cin>>n) {
		for (a=(sqrt((double) 1+8*n)-1)/2;(1+a)*a/2<n;a++) ;
		if (++a%2) b=n-((a-1)*(a-2)/2);
		else b=a-n+(a-1)*(a-2)/2;
		cout<<"TERM "<<n<<" IS "<<b<<"/"<<a-b<<endl;
	}
}