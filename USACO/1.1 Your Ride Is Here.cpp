/*
ID: m80126c2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    string s;
	int a,b,i;
	for (fin>>s,i=0,a=1;i<s.size();i++) a*=s[i]-64;
	for (fin>>s,i=0,b=1;i<s.size();i++) b*=s[i]-64;
    if (a%47==b%47) fout<<"GO"<<endl;
	else fout<<"STAY"<<endl;
}