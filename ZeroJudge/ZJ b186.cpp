#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	while (cin>>a>>b>>c) {
		cout<<a<<" �ӻ氮�A"<<b+min(a/10,c/2)<<" �����J�O�A"<<c<<" �ӳJ�|�C"<<endl;
	}
}