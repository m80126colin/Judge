/**
 *  @judge CPE
 *  @id 10422
 *  @tag Simple, Math
 */
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
 A + 4B + 4C =                                  a^2
 A + 3B + 2C =                       (pi / 2) * a^2
 A + 2B +  C = (pi * (2 / 3) - sqrt( 3 ) / 4) * a^2
  A =  1 + pi * (2 / 3) -     sqrt( 3 )
 4B = -4 + pi * (2 / 3) + 2 * sqrt( 3 )
 4C =  4 - pi * (4 / 3) -     sqrt( 3 )
*/

int main() {
	double a,x,y,z;
	cout<<showpoint<<fixed;
	while (cin>>a) {
		x=(1.0+2.0*acos(0.0)/3-pow(3,0.5))*a*a; /* 1 + pi * (2 / 3) - sqrt( 3 ) */
		y=(-4.0+2.0*acos(0.0)/3+pow(3,0.5)*2)*a*a; /* -4 + pi * (2 / 3) + 2 * sqrt( 3 ) */
		z=(4.0-4.0*acos(0.0)/3-pow(3,0.5))*a*a; /* 4 - pi * (4 / 3) - sqrt( 3 ) */
		cout<<setprecision(3)<<x<<" "<<y<<" "<<z<<endl;
	}
}