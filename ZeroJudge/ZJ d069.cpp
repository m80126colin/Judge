#include <iostream>
using namespace std;

int main() {
	int x,y;
	for (cin>>y;y;y--) {
		cin>>x;
		cout<<((x%4||!(x%100)&&x%400) ? "a normal year" : "a leap year")<<endl;
	}
}