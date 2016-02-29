#include <iostream>
using namespace std;

int main() {
	int n,i,j;
	i=-1;
	for (cin>>n;n;n--) {
		cin>>j;
		i=max(i,j);
	}
	cout<<i<<endl;
}