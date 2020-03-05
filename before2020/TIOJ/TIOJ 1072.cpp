#include <iostream>
#include <algorithm>
using namespace std;

struct dish{
       int c,e;
}d[10000];

bool cmp(dish x,dish y) {
     return (x.e>y.e)||(x.e==y.e)*(x.c>y.c);
}

int main() {
    int n,i,t,temp;
    while (scanf("%d",&n),n) {
          for (i=0;i<n;i++) scanf("%d %d",&d[i].c,&d[i].e);
          sort(d+0,d+n,cmp);
          t=d[0].c;
          temp=d[0].e;
          for (i=1;i<n;i++) {
              t+=d[i].c;
              temp-=d[i].c;
              temp=max(temp,d[i].e);
          }
          printf("%d\n",t+temp);
    }
}
