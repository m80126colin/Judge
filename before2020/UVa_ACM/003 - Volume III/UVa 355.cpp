#include <iostream>
#include <string>
using namespace std;

int a[128];
string b[16];

int out(long long x,int y) {
	if (x/y) out(x/y,y);
	cout<<b[x%y];
	return 0;
}

int main() {
	string k;
	bool ox;
	int m,n,i;
	long long s;
	a['0']=0;a['1']=1;a['2']=2;a['3']=3;a['4']=4;a['5']=5;a['6']=6;a['7']=7;
	a['8']=8;a['9']=9;a['A']=10;a['B']=11;a['C']=12;a['D']=13;a['E']=14;a['F']=15;
	b[0]="0";b[1]="1";b[2]="2";b[3]="3";b[4]="4";b[5]="5";b[6]="6";b[7]="7";
	b[8]="8";b[9]="9";b[10]="A";b[11]="B";b[12]="C";b[13]="D";b[14]="E";b[15]="F";
	while (cin>>m>>n>>k) {
		s=0;
		ox=1;
		for (i=0;i<k.size();i++) {
			if (a[k[i]]>=m) {
				ox=0;
				break;
			}
			s+=a[k[i]];
			if (i<k.size()-1) s*=m;
		}
		if (ox) {
			cout<<k<<" base "<<m<<" = "; 
			out(s,n);
			cout<<" base "<<n;
		}
		else cout<<k<<" is an illegal base "<<m<<" number";
		cout<<endl;
	}
}