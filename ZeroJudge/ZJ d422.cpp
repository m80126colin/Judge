#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string s;
    int a,i;
    const char j=32;
    for (;getline(cin,s);cout<<endl) {
        a=0;
        for (i=0;i<s.size();i++) {
            if (s[i]>='0'&&s[i]<='9') {
                 a+=s[i]-48;
            }
            if (s[i]=='b') {
                 cout<<setfill(j)<<setw(a)<<"";
                 a=0;
            }
            else if (s[i]=='!') {
                 cout<<endl;
                 a=0;
            }
            else if (s[i]>'9'||s[i]<'0') {
                 cout<<setfill(s[i])<<setw(a)<<"";
                 a=0;
            }
        }
    }
}
