/**
 *  @judge ZeroJudge
 *  @id c012
 *  @tag Easy, String, Sorting, Counting frequency
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	string n;
	int ch[128],t;
	ox=0;
	while (getline(cin,n)) {
		if (ox) cout<<endl;
		for (ch[0]=127;ch[0];ch[0]--) ch[ch[0]]=0;
		for (ch[0]=0;ch[0]<n.size();ch[0]++) ch[n[ch[0]]]++;
		for (ch[0]=1;ch[0]<=n.size();ch[0]++) {
			for (t=127;t;t--) {
				if (ch[t]==ch[0]) cout<<t<<" "<<ch[t]<<endl;
			}
		}
		ox=1;
	}
}