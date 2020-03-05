//五行程式版by許胖
#include <iostream>
using namespace std;
int n,m;long long k,i,f[48];
inline void re() {while (i>=3) (k<=f[i-2]) ? i-=2 : (i--,k-=f[i-1]);}
int main() {for (f[1]=f[2]=1,n=3;n<=47;n++) f[n]=f[n-1]+f[n-2];for (cin>>n;n;n--) cin>>m>>k,i=min(m,47),(f[i]<k) ? cout<<-1<<endl : (re(),cout<<((i&1) ? 0 : 1)<<endl);}