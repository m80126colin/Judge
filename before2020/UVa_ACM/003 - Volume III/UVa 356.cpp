#include <iostream>
using namespace std;

int main() {
	bool ox;
	int x,y,n,t,r;
	ox=0;
	while (cin>>n) {
		t=r=0;
		for (x=2;x<=2*n;x+=2) {
			for (y=2;y<=2*n;y+=2) {
				if ((double) x*x+y*y<=(double) (2*n-1)*(2*n-1)) t++;
				else if ((double) (x-2)*(x-2)+(y-2)*(y-2)<(double) (2*n-1)*(2*n-1)) r++;
			}
		}
		if (ox) cout<<endl;
		cout<<"In the case n = "<<n<<", "<<r*4<<" cells contain segments of the circle.\nThere are "<<t*4<<" cells completely contained in the circle.\n";
		ox=1;
	}
}