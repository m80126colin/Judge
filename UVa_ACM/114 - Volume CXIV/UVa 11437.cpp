#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double ax,bx,cx,ay,by,cy,s;
	for (cin>>n;n;n--) {
		cin>>ax>>ay>>bx>>by>>cx>>cy;
		s=fabs(ax*by+bx*cy+cx*ay-bx*ay-cx*by-ax*cy)/14.0;
		cout<<fixed<<setprecision(0)<<s<<endl;
	}
}