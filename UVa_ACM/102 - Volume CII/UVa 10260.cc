#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	string s,t;
	while (getline(cin,s)) {
		t="";
		if (s[0]=='B'||s[0]=='F'||s[0]=='P'||s[0]=='V') t+="1";
		if (s[0]=='C'||s[0]=='G'||s[0]=='J'||s[0]=='K'||s[0]=='Q'||s[0]=='S'||s[0]=='X'||s[0]=='Z') t+="2";
		if (s[0]=='D'||s[0]=='T') t+="3";
		if (s[0]=='L') t+="4";
		if (s[0]=='M'||s[0]=='N') t+="5";
		if (s[0]=='R') t+="6";
		for (i=1;i<s.size();i++) {
			if ((s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V')&&!(s[i-1]=='B'||s[i-1]=='F'||s[i-1]=='P'||s[i-1]=='V')) t+="1";
			if ((s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z')&&!(s[i-1]=='C'||s[i-1]=='G'||s[i-1]=='J'||s[i-1]=='K'||s[i-1]=='Q'||s[i-1]=='S'||s[i-1]=='X'||s[i-1]=='Z')) t+="2";
			if ((s[i]=='D'||s[i]=='T')&&!(s[i-1]=='D'||s[i-1]=='T')) t+="3";
			if (s[i]=='L'&&!(s[i-1]=='L')) t+="4";
			if ((s[i]=='M'||s[i]=='N')&&!(s[i-1]=='M'||s[i-1]=='N')) t+="5";
			if (s[i]=='R'&&!(s[i-1]=='R')) t+="6";
		}
		cout<<t<<endl;
	}
}