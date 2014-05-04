/*
ID: m80126c2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("friday.in");
ofstream fout ("friday.out");

int main() {
	int l[2][12]={{31,31,28,31,30,31,30,31,31,30,31,30},{31,31,29,31,30,31,30,31,31,30,31,30}};
	int n,i,j,k,sum[7],d;
	fin>>n;
	d=3;
	for (i=0;i<7;i++) sum[i]=0;
	for (i=1900;i<1900+n;i++) {
		if ((!(i%4)&&i%100)||!(i%400)) k=1;
		else k=0;
		for (j=0;j<12;j++) {
			d=(d+l[k][j])%7;
			sum[d]++;
		}
	}
	fout<<sum[6];
	for (i=0;i<6;i++) fout<<" "<<sum[i];
	fout<<endl;
}