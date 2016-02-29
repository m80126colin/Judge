#include <iostream>
using namespace std;

int main() {
	int h,m;
	cin>>h>>m;
	cout<<((h<7||h==7&&m<30||h>=17) ? "Off School" : "At School")<<endl;
}