#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double ax,bx,cx,ay,by,cy;
	for (cin>>n;n;n--) {
		cin>>ax>>ay>>bx>>by>>cx>>cy;
		cout<<fixed<<setprecision(0)<<abs(ax*by+bx*cy+cx*ay-bx*ay-cx*by-ax*cy)/14.0<<endl;
	}
}