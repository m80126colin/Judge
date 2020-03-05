#include <stdio.h>
inline int min(int x,int y) {
	return (x<y) ? x : y;
}
inline int max(int x,int y) {
	return (x>y) ? x : y;
}
int main() {
	int minn,maxn;
	int t,l,n,i,ant;
	for (scanf("%d",&t);t;t--) {
		minn=maxn=0;
		scanf("%d%d",&l,&n);
		for (i=0;i<n;i++) {
			scanf("%d",&ant);
			minn=max( minn, min(ant,l-ant) );
			maxn=max( maxn, max(ant,l-ant) );
		}
		printf("%d %d\n",minn,maxn);
	}
}