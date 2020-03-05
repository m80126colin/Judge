#include <iostream>
#include <string>
using namespace std;

int main() {
	int k,i,j,t;
	string s;
	while (cin>>k>>s) {
		t=0;
		for (i=1;i+k<=s.size();i++) {
			for (j=i-1;j>=0;j--) {
				if (j>=0&&(2*i+k-j-1)<s.size()) {
					if (s.substr(j,i-j)==s.substr(i+k,i-j)) t++;
				}
			}
		}
		cout<<t<<endl;
	}
}