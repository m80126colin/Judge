#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int i,ctr;
	string s,t;
	stringstream ss;
	while (cin>>s,s!="END") {
		i=s.size();
		ss.clear();
		ss.str("");
		ss<<i;
		t=ss.str();
		ctr=1;
		while (s!=t) {
			s=t;
			i=s.size();
			ss.clear();
			ss.str("");
			ss<<i;
			t=ss.str();
			ctr++;
		}
		cout<<ctr<<endl;
	}
}