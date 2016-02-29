#include <stdio.h>
int gcd(int a,int b){return(b)?gcd(b,a%b):a;}
int main(){int a,b;while(scanf("%d%d",&a,&b)!=EOF)printf("%d\n",gcd(a,b));}