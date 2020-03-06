/**
 *  @judge ZeroJudge
 *  @id a020
 *  @tag Easy, Ad-hoc
 */
#include <iostream>
#include <string>
using namespace std;

string n;
int a;

int tt(char x) {
	if (x=='A') n[0]=10;
	else if (x=='B') n[0]=11;
	else if (x=='C') n[0]=12;
	else if (x=='D') n[0]=13;
	else if (x=='E') n[0]=14;
	else if (x=='F') n[0]=15;
	else if (x=='G') n[0]=16;
	else if (x=='H') n[0]=17;
	else if (x=='I') n[0]=24;
	else if (x=='J') n[0]=18;
	else if (x=='K') n[0]=19;
	else if (x=='L') n[0]=20;
	else if (x=='M') n[0]=21;
	else if (x=='N') n[0]=22;
	else if (x=='O') n[0]=35;
	else if (x=='P') n[0]=23;
	else if (x=='Q') n[0]=24;
	else if (x=='R') n[0]=25;
	else if (x=='S') n[0]=26;
	else if (x=='T') n[0]=27;
	else if (x=='U') n[0]=28;
	else if (x=='V') n[0]=29;
	else if (x=='W') n[0]=32;
	else if (x=='X') n[0]=30;
	else if (x=='Y') n[0]=31;
	else if (x=='Z') n[0]=33;
	return 0;
}

int main() {
	while (cin>>n) {
		tt(n[0]);
		a=n[0]/10+n[0]%10*9+(n[1]-48)*8+(n[2]-48)*7+(n[3]-48)*6+(n[4]-48)*5+(n[5]-48)*4+(n[6]-48)*3+(n[7]-48)*2+(n[8]-48)+(n[9]-48);
		if (a%10==0) cout<<"real"<<endl;
		else cout<<"fake"<<endl;
	}
}