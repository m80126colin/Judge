#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double f;
	while (cin>>f) cout<<fixed<<setprecision(3)<<(f-32)*5/9<<endl;
}