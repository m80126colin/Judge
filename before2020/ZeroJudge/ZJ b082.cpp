#include <iostream>
#include <string>
using namespace std;

struct bone{
	int a;
	char ch;
	int b;
};

int main() {
	string s,ss;
	int n,m,i,t;
	bone x[302];
	for (cin>>n;n;n--) {
		for (cin>>m,i=1;i<=m;i++) cin>>x[i].a>>x[i].ch>>x[i].b;
		s="";
		for (t=i=1,s+=x[t].ch;i<=m;i++) {
			if (x[t].b==x[i].a) {
				s+=x[i].ch;
				t=i;
				i=1;
			}
		}
		for (t=i=1;i<=m;i++) {
			if (x[t].a==x[i].b) {
				ss=x[i].ch;
				s.insert(0,ss);
				t=i;
				i=1;
			}
		}
		cout<<s<<endl;
	}
}