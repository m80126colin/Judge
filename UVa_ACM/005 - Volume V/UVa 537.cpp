#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main() {
	bool ou,op,oi;
	int n,c,j;
	double u,p,i;
	string s,t;
	stringstream ss;
	for (cin>>n,c=1,cin.ignore(1);c<=n;c++) {
		ou=op=oi=0;
		getline(cin,s);
		ss.clear();
		ss.str(s);
		while (ss>>t) {
			if (t[1]=='=') {
				for (j=2;j<t.size();j++) {
					if ((t[j]>'9'||t[j]<'0')&&t[j]!='.') break;
				}
				double k;
				string num;
				stringstream nanj;
				nanj.clear();
				num=t.substr(2,j-2);
				nanj.str(num);
				nanj>>k;
				if (t[j]=='m') k/=1000;
				if (t[j]=='k') k*=1000;
				if (t[j]=='M') k*=1000000;
				if (t[0]=='U') ou=1,u=k;
				if (t[0]=='P') op=1,p=k;
				if (t[0]=='I') oi=1,i=k;
			}
		}
		if (ou&&op) i=p/u;
		if (ou&&oi) p=u*i;
		if (oi&&op) u=p/i;
		cout<<"Problem #"<<c<<endl;
		if (!ou) cout<<"U="<<fixed<<setprecision(2)<<u<<"V\n";
		if (!op) cout<<"P="<<fixed<<setprecision(2)<<p<<"W\n";
		if (!oi) cout<<"I="<<fixed<<setprecision(2)<<i<<"A\n";
		cout<<endl;
	}
}