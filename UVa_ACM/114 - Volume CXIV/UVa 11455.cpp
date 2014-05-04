#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t,s[5];
	for (cin>>t;t;t--) {
		for (s[0]=1;s[0]<=4;s[0]++) cin>>s[s[0]];
		sort (s+1,s+5);
		if (((s[1]+s[2]+s[3])<=s[4])||((s[1]==0)||(s[2]==0)||(s[3]==0)||(s[4]==0))) cout<<"banana"<<endl;
		else if ((s[1]!=s[2])||(s[3]!=s[4])) cout<<"quadrangle"<<endl;
		else if (s[2]!=s[3]) cout<<"rectangle"<<endl;
		else cout<<"square"<<endl;
	}
}