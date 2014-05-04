#include <iostream>
using namespace std;
int a[101][101];
inline void getd (int &d) {char ch;while (!isdigit(ch=getchar()));d=0;do {(d*=10)+=ch-'0';}while (isdigit(ch=getchar()));}
int main() {for (int n,i,j;~scanf("%d",&n);printf("%d\n",a[n][n])) for (i=j=1;i<=n&&j<=n;(j==n)?(i++,j=1):j++) getd(a[i][j]),a[i][j]+=max(a[i][j-1],a[i-1][j]);}