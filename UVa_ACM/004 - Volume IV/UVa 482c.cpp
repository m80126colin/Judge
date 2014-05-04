#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node{
	int index;
	char s[100];
};
int cmp(const void *a,const void *b) {
	return ((Node *)a)->index - ((Node *)b)->index;
}
int main() {
	int t,n,i;
	char ch;
	Node s[1000];
	for (scanf("%d",&t);t;t--) {
		for (n=0;scanf("%d%c",&s[n].index,&ch);) {
			n++;
			if (ch=='\n') break;
		}
		for (i=0;i<n;i++) scanf("%s",s[i].s);
		qsort(s,n,sizeof(Node),cmp);
		for (i=0;i<n;i++) puts(s[i].s);
		if (t>1) puts("");
	}
}