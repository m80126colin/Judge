#include <iostream>
#include <string>
using namespace std;

int a[128];
long long s1,s2;

int op(string x) {
	int i,j;
	for (i=j=0;i<x.size();i++) {
		j=max(j,a[x[i]]);
	}
	return j+1;
}

int in(string x,int y,long long &z) {
	int i;
	for (i=0;i<x.size();i++) {
		z+=a[x[i]];
		if (i<x.size()-1) z*=y;
	}
	return 0;
}

int main() {
	bool ox;
	string m,n;
	int i,j;
	a['0']=0;a['1']=1;a['2']=2;a['3']=3;a['4']=4;a['5']=5;a['6']=6;a['7']=7;a['8']=8;
	a['9']=9;a['A']=10;a['B']=11;a['C']=12;a['D']=13;a['E']=14;a['F']=15;a['G']=16;a['H']=17;
	a['I']=18;a['J']=19;a['K']=20;a['L']=21;a['M']=22;a['N']=23;a['O']=24;a['P']=25;a['Q']=26;
	a['R']=27;a['S']=28;a['T']=29;a['U']=30;a['V']=31;a['W']=32;a['X']=33;a['Y']=34;a['Z']=35;
	while (cin>>m>>n) {
		ox=1;
		for (i=max(op(m),2);i<=36&&ox;i++) {
			for (j=max(op(n),2);j<=36;j++) {
				s1=s2=0;
				in(m,i,s1);
				in(n,j,s2);
				if (s1==s2) {
					cout<<m<<" (base "<<i<<") = "<<n<<" (base "<<j<<")";
					ox=0;
					break;
				}
			}
		}
		if (i>36&&j>36) cout<<m<<" is not equal to "<<n<<" in any base 2..36";
		cout<<endl;
	}
}