#include <iostream>
using namespace std;

int main() {
	int i;
	while (cin>>i) cout<<( (i<0) ? "-" : "" )<<(i!=0)<<endl;
}