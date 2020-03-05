#include <iostream>
using namespace std;

int main() {
    int a[5],b[5],i,n,c,w[5]={1,5,10,20,50};
    for (scanf("%d",&n);n;n--) {
        scanf("%d",&c);
        for (i=0;i<5;i++) scanf("%d",&a[i]);
        for (i=0;i<5;i++) scanf("%d",&b[i]);
        c=-c;
        for (i=0;i<5;i++) c+=a[i]*w[i],a[i]+=b[i];
        for (i=4;i>=0;i--) {
            int temp=min(c/w[i],a[i]);
            b[i]=temp;
            c-=temp*w[i];
        }
        for (c=i=0;i<5;i++) c+=b[i];
        printf("%d\n",c);
    }
}
