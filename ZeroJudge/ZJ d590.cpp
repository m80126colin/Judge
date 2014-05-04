#include <iostream>
using namespace std;

int main() {
	int n,m;
	while (cin>>n>>m,n||m) cout<<( ((n+m)&1) ? "Loss" : "Win" )<<endl;
}