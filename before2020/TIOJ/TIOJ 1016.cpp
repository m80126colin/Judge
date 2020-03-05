#include <iostream>
#include <string>
using namespace std;

bool ox[18];
int out,base[2][4];

inline void clear() {
	int i;
	for (i=0;i<3;i++) base[(out/3)&1][i]=0;
	return;
}

inline void home() {
	int i;
	base[(out/3)&1][3]++;
	for (i=0;i<3;i++) base[(out/3)&1][3]+=base[(out/3)&1][i];
	clear();
	return;
}

inline void hit(int x) {
	int i;
	for (i=3-x;i<3;i++) base[(out/3)&1][3]+=base[(out/3)&1][i];
	for (i=2;i>=x;i--) base[(out/3)&1][i]=base[(out/3)&1][i-x];
	for (i=x-1;i>=0;i--) base[(out/3)&1][i]=0;
	base[(out/3)&1][x-1]++;
	return;
}

inline void walk() {
	int i;
	base[(out/3)&1][0]++;
	for (i=1;i<4;i++) if (base[(out/3)&1][i-1]>1) base[(out/3)&1][i-1]--,base[(out/3)&1][i]++;
	return;
}

int main() {
	int i;
	string s;
	while (getline(cin,s)) {
		for (i=0;i<18;i++) ox[i]=1;
		for (out=base[0][3]=base[1][3]=i=0;i<s.size();i++) {
			if (!(out%3)&&ox[out/3]) clear(),ox[out/3]=0;
			if (s[i]=='K'||s[i]=='O') out++;
			else if (s[i]=='H') home();
			else if (s[i]=='S') hit(1);
			else if (s[i]=='D') hit(2);
			else if (s[i]=='T') hit(3);
			else walk();
		}
		printf("%d %d\n",base[0][3],base[1][3]);
	}
}