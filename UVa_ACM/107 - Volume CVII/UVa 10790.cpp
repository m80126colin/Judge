#include <iostream>
using namespace std;

int main() {
	long long a,b,c,d;
	c=1;
	for (cin>>a>>b;a&&b;cin>>a>>b) cout<<"Case "<<c++<<": "<<a*(a-1)*b*(b-1)/4<<endl;
}