#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int n,i,j,a;
	while (cin>>n) {
		for (a=(-1+pow((double) 1+8*n,0.5))/2;a*(a+1)<2*n;a++) ;
		a++;
		j=n-(a-2)*(a-1)/2;
		i=a-j;
		if (a%2) swap(i,j);
		cout<<"TERM "<<n<<" IS "<<i<<"/"<<j<<endl;
	}
}