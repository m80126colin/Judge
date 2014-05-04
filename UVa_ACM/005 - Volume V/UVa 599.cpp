#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool p[26];
string s;
vector <int> v[26];
int t,a,b,tr,ac;

inline void ad(int x) {
	int i;
	if (p[x]) {
		p[x]=0;
		for (i=0;i<v[x].size();i++) ad(v[x][i]);
	}
}

int main() {

	for (cin>>t;t;t--) {
		for (a=0;a<26;a++) v[a].clear();
		while (cin>>s,s[0]!='*') {
			a=s[1]-'A',b=s[3]-'A';
			v[a].push_back(b);
			v[b].push_back(a);
		}
		tr=ac=0;
		memset(p,0,sizeof(p));
		cin>>s;
		for (a=0;a<s.size();a+=2) p[s[a]-'A']=1;
		for (a=0;a<26;a++) {
			if (p[a]) {
				int i;
				p[a]=0;
				if (v[a].empty()) ac++;
				else {
					tr++;
					for (i=0;i<v[a].size();i++) ad(v[a][i]);
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n",tr,ac);
	}
}