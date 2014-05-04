#include <iostream>
using namespace std;

int main() {
	int x,y,i;
	for (cin>>y,i=1;i<=y;i++) {
		cin>>x;
		cout<<"Case "<<i<<": "<<((x%4||!(x%100)&&x%400) ? "a normal year" : "a leap year")<<endl;
	}
}