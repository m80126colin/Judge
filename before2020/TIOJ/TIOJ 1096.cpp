#include <iostream>
#define MAX 100
using namespace std;

int main() {
    int n,i,j,k,stat[MAX][MAX];
    while (scanf("%d",&n),n) {
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                scanf("%d",&stat[i][j]);
                if (!stat[i][j]) stat[i][j]=10e8;
            }
        }
        for (k=0;k<n;k++) {
            for (i=0;i<n;i++) {
                for (j=0;j<n;j++) stat[i][j]=min(stat[i][k]+stat[k][j],stat[i][j]);
            }
        }
        k=10e8;
        for (i=0;i<n;i++) k=min(k,stat[i][i]);
        if (k==10e8) k=-1;
        printf("%d\n",k);
    }
}
