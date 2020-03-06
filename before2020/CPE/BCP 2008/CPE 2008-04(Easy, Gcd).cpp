/**
 *  @judge CPE
 *  @id 2008-04
 *  @tag Easy, Gcd
 */
#include <stdio.h>
int gcd(int a, int b){return (b) ? gcd(b, a%b): a;}
int main(){int a, b, ctr;for (ctr = 1; scanf("%d%d",&a,&b)!=EOF; ctr++) printf("case %d:\n%d\n\n", ctr, gcd(a, b));}