/**
 *  @judge ZeroJudge
 *  @id c054
 *  @tag Easy, String manipulation
 */
#include <iostream>
using namespace std;

int main() {
	char n;
	while (cin.get(n)) {
		if (n=='1') cout<<'`';
		if (n=='2') cout<<'1';
		if (n=='3') cout<<'2';
		if (n=='4') cout<<'3';
		if (n=='5') cout<<'4';
		if (n=='6') cout<<'5';
		if (n=='7') cout<<'6';
		if (n=='8') cout<<'7';
		if (n=='9') cout<<'8';
		if (n=='0') cout<<'9';
		if (n=='-') cout<<'0';
		if (n=='=') cout<<'-';
		if (n=='\b') cout<<'=';
		if (n=='W') cout<<'Q';
		if (n=='E') cout<<'W';
		if (n=='R') cout<<'E';
		if (n=='T') cout<<'R';
		if (n=='Y') cout<<'T';
		if (n=='U') cout<<'Y';
		if (n=='I') cout<<'U';
		if (n=='O') cout<<'I';
		if (n=='P') cout<<'O';
		if (n=='[') cout<<'P';
		if (n==']') cout<<'[';
		if (n=='\\') cout<<']';
		if (n=='S') cout<<'A';
		if (n=='D') cout<<'S';
		if (n=='F') cout<<'D';
		if (n=='G') cout<<'F';
		if (n=='H') cout<<'G';
		if (n=='J') cout<<'H';
		if (n=='K') cout<<'J';
		if (n=='L') cout<<'K';
		if (n==';') cout<<'L';
		if (n=='\'') cout<<';';
		if (n=='\n') cout<<'\n';
		if (n=='X') cout<<'Z';
		if (n=='C') cout<<'X';
		if (n=='V') cout<<'C';
		if (n=='B') cout<<'V';
		if (n=='N') cout<<'B';
		if (n=='M') cout<<'N';
		if (n==',') cout<<'M';
		if (n=='.') cout<<',';
		if (n=='/') cout<<'.';
		if (n==' ') cout<<' ';
	}
}