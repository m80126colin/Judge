/*
Problem: d550 (short version)
Language: C++
Result: AC (395ms, 5355KB) on ZeroJudge
Author: m80126colin at 2010-07-09 14:39:35
Solution: Straight Forward
*/
#include <iostream>
int n,m,s[10001][201],h[10001],i,j,z;
bool cmp(int x,int y){for (z=m;z&&s[x][z]==s[y][z];z--) ;return s[x][z]>s[y][z];}
int a(){for (i=n,j=--m;i;j?j--:(j=m,h[i]=i--))scanf("%d",&s[i][j]);for (std::sort(h+1,h+n+1,cmp),i=n,j=m;i;j?j--:(i--,j=m,putchar(10)))printf("%d ",s[h[i]][j]);return 1;}
int main(){~scanf("%d%d",&n,&m)&&a()&& main();}