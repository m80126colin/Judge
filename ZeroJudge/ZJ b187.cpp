#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout<<"十六進位表示法  相對應的十進位表示法"<<endl;
	while (cin>>s) cout<<"      "<<s<<"                 "<<strtol(&s[0],0,16)<<endl;
}