#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() { 
    long long i,j;
    string s;
    stringstream ss;
    while (getline(cin,s)) {
          i=j=0;
          ss.str(s);
          while (ss>>j) i+=j;
          cout<<i<<endl;
          ss.clear();
          }
    }
