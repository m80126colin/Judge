#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double k,ax,ay,bx,by;
	cout<<showpoint<<fixed;
	for (cin>>n;n;n--) {
		cin>>ax>>ay>>bx>>by;
		k=pow(((ax+bx)*(ax+bx)+(ay+by)*(ay+by)),0.5)+pow(((ax-bx)*(ax-bx)+(ay-by)*(ay-by)),0.5);
		cout<<setprecision(3)<<k<<endl;
	}
}