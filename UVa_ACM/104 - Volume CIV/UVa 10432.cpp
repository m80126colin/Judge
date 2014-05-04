#include <iostream> 
#include <iomanip> 
#include <math.h> 
using namespace std; 

int main() { 
        double s,r,n; 
        while (cin>>r>>n) { 
                s=sin(acos(-1.0)*2.0/n)*r*r/2.0*n; 
                cout<<fixed<<setprecision(3)<<s<<endl; 
        } 
} 