#include <iostream>
#include <string>
using namespace std;

int main() {
    bool ox;
    long long i,a,b;
    string n,s;
    n="";
    a=b=0;
    ox=0;
    while (getline(cin,s)) n+=s;
    for (i=0;i<n.size();i++) {
        if (n[i]>='0'&&n[i]<='9') {
            a+=n[i]-48;
            ox=1;
        }
        if (ox&&n[i+1]>='0'&&n[i+1]<='9'&&n[i]>='0'&&n[i]<='9') a*=10;
        if (ox&&(n[i]<'0'||n[i]>'9')) {
            ox=0;
            break;
        }
    }
    for (i;i<n.size();i++) {
        if (n[i]>='0'&&n[i]<='9') {
            b+=n[i]-48;
            ox=1;
        }
        if (ox&&n[i+1]>='0'&&n[i+1]<='9'&&n[i]>='0'&&n[i]<='9') b*=10;
        if (ox&&(n[i]<'0'||n[i]>'9')) break;
    }
    cout<<a<<" "<<b<<" "<<a+b<<endl;
    system("PAUSE");
}
