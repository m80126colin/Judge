#include <iostream>
using namespace std;

int main() {
    int t,a,b,i;
    for (i=1,cin>>t;i<=t;i++) {
        cin>>a>>b;
        a+=(!(a%2)),b-=(!(b%2));
        cout<<"Case "<<i<<": "<<(a+b)*((b-a)/2+1)/2<<endl;
        }
    }
