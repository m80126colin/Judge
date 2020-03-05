#include <iostream>
using namespace std;

int sum(int x,int y) {
    int i;
    if (!x) return y;
    cin>>i;
    return sum(x-1,i+y);
    }

int main() {
    int n;
    cin>>n;
    cout<<sum(n,0)<<endl;
    }
