/**
 *  @judge ZeroJudge
 *  @id c002
 *  @tag Easy, Math, McCarthy 91 function
 */
#include <iostream>
using namespace std;

int main() {
	int n,x;
	while (cin>>n&&n) {
		if (n<102) x=91;
		else x=n-10;
		cout<<"f91("<<n<<") = "<<x<<endl;
	}
} 