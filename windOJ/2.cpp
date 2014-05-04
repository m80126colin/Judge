#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int i,sum;
	while (getline(cin,s)&&s!="0") {
		for (sum=0,i=0;i<s.size();i++) {
			int j;
			j=s[i]+1-((s[i]>='a') ? 'a':'A');
			if (!(j<=26&&j>0)) break;
			else sum+=j;
		}
		if (i==s.size()) cout<<sum<<endl;
		else cout<<"Fail\n";
	}
}