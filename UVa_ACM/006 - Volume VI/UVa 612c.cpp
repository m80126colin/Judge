#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node Node;
struct node{
	int io,unsortion;
	char s[51];
};
int cmp(const void *left,const void *right) {
	Node *a=(Node *)left;
	Node *b=(Node *)right;
	if (a->unsortion != b->unsortion) return a->unsortion - b->unsortion;
	return a->io - b->io;
}
int main() {
	int t,n,m,i,j,k,len;
	int num[4];
	char list[5]="ACGT";
	Node dna[100];
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&n,&m);
		for (i=0;i<m;i++) {
			scanf("%s",dna[i].s);
			len=strlen(dna[i].s);
			dna[i].unsortion=0;
			dna[i].io=i;
			for (j=0;j<4;j++) num[j]=0;
			for (j=0;j<len;j++) {
				for (k=0;k<4;k++) {
					if (list[k]==dna[i].s[j]) {
						num[k]++;
						break;
					}
				}
				for (k++;k<4;k++) dna[i].unsortion+=num[k];
			}
		}
		qsort(dna,m,sizeof(Node),cmp);
		for (i=0;i<m;i++) printf("%s\n",dna[i].s);
		if (t>1) puts("");
	}
}