/**
 *  @judge ZeroJudge
 *  @id d186
 *  @source UVa 11461
 * 
 *  @tag Easy, Brute force, Number Theory
 */
#include <iostream>
using namespace std;

int main() {
	int a,b,i,t;
	while (cin>>a>>b&&a&&b) {
		t=0;
		for (i=1;i*i<=b;i++) {
			if (i*i>=a) t++;
		}
		cout<<t<<endl;
	}
}