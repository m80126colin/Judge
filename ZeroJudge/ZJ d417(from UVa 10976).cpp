#include <iostream>
#include <string>
using namespace std;

int main() {
	int k,x,y;
	string z;
	while (cin>>k) {
		z="";
		x=0;
		for (y=k+1;y<=2*k;y++) {
			if ((y*k)%(y-k)==0) {
				x++;
			}
		}
		cout<<x<<endl;
		for (y=k+1;y<=2*k;y++) {
			if ((y*k)%(y-k)==0) {
				cout<<"1/"<<k<<" = 1/"<<(y*k)/(y-k)<<" + 1/"<<y<<endl;
			}
		}
	}
}