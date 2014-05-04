#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct point Point;
struct point {
	char s[17];
	int p;
};
Point hay[10000];
int cmp(const void *a, const void *b) {
	return strcmp(((Point *)a)->s,((Point *)b)->s);
}
int find_string(char *s,int i,int j) {
	int pivot;
	if (i>j) return -1;
	pivot=(i+j)/2;
	if (strcmp(hay[pivot].s,s)>0) return find_string(s,i,pivot-1);
	else if (strcmp(hay[pivot].s,s)<0) return find_string(s,pivot+1,j);
	else return pivot;
}
int main() {
	int m,n,i,j,sum;
	char input[1000];
	while (scanf("%d%d",&m,&n)!=EOF) {
		for (i=0;i<m;i++) scanf("%s%d",hay[i].s,&hay[i].p);
		qsort(hay,m,sizeof(Point),cmp);
		for (i=0;i<n;i++) {
			sum=0;
			while (scanf("%s",&input),strcmp(input,".")) {
				if ((j=find_string(input,0,m-1))>=0) 
					sum+=hay[j].p;
			}
			printf("%d\n",sum);
		}
	}
}