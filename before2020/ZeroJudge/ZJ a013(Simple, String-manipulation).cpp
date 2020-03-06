/**
 *  @judge ZeroJudge
 *  @id a013
 *  @tag Simple, String Manipulation
 */
#include <iostream>
#include <string>
using namespace std;

string n,b[1001];
int a[128];

int in(string x,int &y) {
	int i;
	for (i=0;i<x.size();i++) {
		if ((i<x.size()-1)&&(a[x[i]]<a[x[i+1]])) y-=a[x[i]];
		else y+=a[x[i]];
	}
	return 0;
}

int out(int &x,int y) {
	int j;
	if ((x/y)%10==4) {cout<<b[y];cout<<b[5*y];x-=4*y;}
	if ((x/y)%10==9) {cout<<b[y];cout<<b[10*y];x-=9*y;}
	if (x/y>4) {cout<<b[5*y];x-=5*y;}
	for (j=1;j<=x/y;j++) cout<<b[y];
	x=x-(x/y)*y;
	return 0;
}

int main() {
	int i,j;
	a['I']=1;a['V']=5;a['X']=10;a['L']=50;a['C']=100;a['D']=500;a['M']=1000;
	b[1]="I";b[5]="V";b[10]="X";b[50]="L";b[100]="C";b[500]="D";b[1000]="M";
	while (cin>>n&&n!="#") {
		i=0;in(n,i);
		cin>>n;
		j=0;in(n,j);
		n="";
		i=abs(i-j);
		if (i) {
			for (j=1000;j;j/=10) {
				if (i/j) out(i,j);
			}
			cout<<endl;
		}
		else cout<<"ZERO"<<endl;
	}
}