#include <iostream>
using namespace std;

long long gcd(int x,int y) {
     if (x%y) return gcd(y,x%y);
     else return y;
     } 

int main() {
    long long a,b,c;
    while (cin>>a>>b) {
          cout<<(a+b)/gcd(a,b)-1<<endl;
          }
    }
