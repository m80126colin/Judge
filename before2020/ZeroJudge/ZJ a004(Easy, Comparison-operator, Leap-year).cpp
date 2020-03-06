/**
 *  @judge ZeroJudge
 *  @id a004
 *  @tag Easy, Comparison operator, Leap year
 */
#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin>>n) {
		if ((n%400==0)||(n%4==0&&n%100)) cout<<"�|�~"<<endl;
		else cout<<"���~"<<endl;
	}
}