#include <iostream>
using namespace std;

int main() {
	long long i[50],j;
	i[0]=1;i[1]=2;
	for (j=2;j<50;j++) i[j]=i[j-1]+i[j-2];
	while (cin>>j&&j) cout<<i[j-1]<<endl;
}