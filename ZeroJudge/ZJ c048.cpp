#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int n,x,y,i;
	while (cin>>n&&n) {
		for (i=pow((double) n,0.5);i*i<n;i++) ;
		x=n-(i-1)*(i-1);
		y=i;
		if (x>i) {
			x=2*i-x;
			swap(x,y);
		}
		if (i%2) swap(x,y);
		cout<<x<<" "<<y<<endl;
	}
}