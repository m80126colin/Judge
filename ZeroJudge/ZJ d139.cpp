#include <iostream>
#include <string>
using namespace std;

int main () {
	int i,cnt;
	string s;
	while (getline(cin,s)) {
		s+=" ";
		cnt=0;
		for (i=0;i<s.size()-1;i++) {
			if (s[i]==s[i+1]) cnt++;
			else {
				if (cnt+1>2) cout<<cnt+1<<s[i];
				else {
					while (cnt+1) cout<<s[i],cnt--;
				}
				cnt=0;
			}
		}
		cout<<endl;
	}
}