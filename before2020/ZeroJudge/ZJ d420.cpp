/**
 *  @judge ZeroJudge
 *  @id d420
 *  @source UVa 694
 */
#include <iostream>
using namespace std;

long long t,a,l,s;

int re() {
	if (a==1) {
		s++;
		return 0;
	}
	if (a>l) return 0;
	if (a%2) {
		s++;
		a=3*a+1;
		re();
	}
	else {
		s++;
		a/=2;
		re();
	}
	return 0;
}

int main() {
	t=1;
	while (cin>>a>>l&&a>=0&&l>=0) {
		s=0;
		cout<<"Case "<<t++<<": A = "<<a<<", limit = "<<l;
		re();
		cout<<", number of terms = "<<s<<endl;
	}
}