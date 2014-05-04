#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int cmp(string x,string y) {
	int i;
	if (x.size()>y.size()) return 1;
	else if (x.size()<y.size()) return -1;
	else {
		for (i=x.size();i;i--) {
			if (x.size()>y.size()) return 1;
			else if (x.size()<y.size()) return -1;
		}
		return 0;
	}
}

int main() {
	long long a,b,m1;
	string s1,s2,t,m2;
	stringstream ss;
	m1=2147483647;
	ss.clear();
	ss.str("");
	ss<<m1;
	m2=ss.str();
	while (getline(cin,s2)) {
		cout<<s2<<endl;
		ss.clear();
		ss.str(s2);
		ss>>s1;
		ss>>t;
		ss>>s2;
		if (cmp(s1,m2)>0) cout<<"first number too big\n";
		if (cmp(s2,m2)>0) cout<<"second number too big\n";
		if (cmp(s1,m2)>0||cmp(s2,m2)>0) {
			if ((t=="*"&&(s1!="0"&&s2!="0"))||t=="+") cout<<"result too big\n";
		}
		else {
			ss.clear();
			ss.str(s1);
			ss>>a;
			ss.clear();
			ss.str(s2);
			ss>>b;
			if (t=="+") a+=b;
			else a*=b;
			if (a>m1) cout<<"result too big\n";
		}
	}
}