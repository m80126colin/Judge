#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int m,s,i[14];
string n,j;
stringstream ss;

int card(string x) {
	if (x=="A") return 1;
	if (x=="2") return 2;
	if (x=="3") return 3;
	if (x=="4") return 4;
	if (x=="5") return 5;
	if (x=="6") return 6;
	if (x=="7") return 7;
	if (x=="8") return 8;
	if (x=="9") return 9;
	if (x=="+10") return 10;
	if (x=="-10") return 10;
	if (x=="J") return 11;
	if (x=="+Q") return 12;
	if (x=="-Q") return 12;
	if (x=="K") return 13;
}

int re(string x,int &y) {
	if (j[j.size()-1]>='2'&&j[j.size()-1]<='9'&&(j[j.size()-1]!='4'&&j[j.size()-1]!='5')) y+=j[j.size()-1]-48;
	else {
		if (j=="+10") y+=10;
		else if (j=="+Q") y+=20;
		else if (j=="-10") y-=10;
		else if (j=="-Q") y-=20;
		else if (j=="K") y=99;
		else if (j=="A") y=0;
	}
	return 0;
}

int main() {
	bool ox;
	while (cin>>s>>m&&(s||m)) {
		ox=1;
		for (s=13;s;s--) i[s]=0;
		cin.ignore(1);
		getline(cin,n);
		ss.clear();
		ss.str(n);
		while (ss>>j) {
			m--;
			i[card(j)]++;
			re(j,s);
			if (s<0) s=0;
			if (s>99||i[card(j)]>4) {
				ox=0;
				cout<<"Unfair game";
				break;
			}
		}
		if (ox) cout<<s;
		cout<<endl;
	}
}