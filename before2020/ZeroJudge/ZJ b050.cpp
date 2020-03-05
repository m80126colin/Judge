#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	char a,b;
	int i,j,k,l,t;
	bool x[26][128],ox;
	for (t=1;cin>>i,i;t++) {
		cin.ignore(1);
		memset(x,0,sizeof(x));
		for (j=0;j<i;j++) {
			getline(cin,s);
			for (k=0;k<s.size();k++) x[j][s[k]]=1;
		}
		printf("Test Case %d:\n",t);
		for (j=0;j<i;j++) {
			for (k=j+1;k<i;k++) {
				a=j+'A',b=k+'A';
				cout<<a<<": {";
				for (l=0;l<128;l++) {if (x[j][l]) printf("%c",l);}
				cout<<"}\n";
				cout<<b<<": {";
				for (l=0;l<128;l++) {if (x[k][l]) printf("%c",l);}
				cout<<"}\n";
				cout<<a<<"+"<<b<<": {";
				for (l=0;l<128;l++) {if (x[j][l]|x[k][l]) printf("%c",l);}
				cout<<"}\n";
				cout<<a<<"*"<<b<<": {";
				for (l=0;l<128;l++) {if (x[j][l]&x[k][l]) printf("%c",l);}
				cout<<"}\n";
				cout<<a<<"-"<<b<<": {";
				for (l=0;l<128;l++) {if (x[j][l]&~x[k][l]) printf("%c",l);}
				cout<<"}\n";
				cout<<b<<"-"<<a<<": {";
				for (l=0;l<128;l++) {if (x[k][l]&~x[j][l]) printf("%c",l);}
				cout<<"}\n";
				for (ox=1,l=0;l<128;l++) {if (x[k][l]&~x[j][l]) ox=0;}
				cout<<a<<((ox) ? " contains " : " does not contain " )<<b<<endl;
				for (ox=1,l=0;l<128;l++) {if (x[j][l]&~x[k][l]) ox=0;}
				cout<<b<<((ox) ? " contains " : " does not contain " )<<a<<endl;
			}
		}
	}
}