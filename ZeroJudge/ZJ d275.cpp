#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n,m,f,i;
    for (cin>>n,cin.ignore(1);n;n--) {
        m=f=0;
        getline(cin,s);
        for (i=0;i<s.size();i++) {
            if (s[i]=='M') m++;
            if (s[i]=='F') f++;
        }
        if (m==f&&m>1) cout<<"LOOP\n";
        else cout<<"NO LOOP\n";
    }
    system("PAUSE");
}
