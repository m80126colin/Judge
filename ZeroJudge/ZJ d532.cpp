#include <iostream>
using namespace std;

int main() {
	int a,b,l=0;
	for (cin>>a>>b;a<=b;a++) if (!(a%4)&&a%100||!(a%400)) l++;
	cout<<l<<endl;
}