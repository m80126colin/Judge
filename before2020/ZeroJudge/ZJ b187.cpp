#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout<<"�Q���i���ܪk  �۹������Q�i���ܪk"<<endl;
	while (cin>>s) cout<<"      "<<s<<"                 "<<strtol(&s[0],0,16)<<endl;
}