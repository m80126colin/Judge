#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a,b;
	while (cin>>a>>b) {
		for (a;a!=b;a+=(a<b)-(a>b)) cout<<setw(a)<<setfill('*')<<""<<endl;
		cout<<setw(a)<<setfill('*')<<""<<endl;
	}
}