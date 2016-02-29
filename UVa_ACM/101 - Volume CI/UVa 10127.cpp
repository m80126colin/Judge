#include <iostream>
using namespace std;

int main() {
	int n,m,t;
	while (cin>>n) {
		for (t=m=1;m;t++) m=(m*10+1)%n;
		cout<<t<<endl;
	}
}