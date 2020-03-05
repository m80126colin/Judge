#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node {
	int child;
	Node *next;
};
int main() {
	int n,i,j;
	int dfs[1001],bfs[1001],dfn[1001],deep[1001];
	Node tree[1001],*current,*ptr;
	while (scanf("%d",&n)!=EOF) {
		for (i=1;i<=n;i++) scanf("%d",&bfs[i]),tree[i].next=NULL;
		for (i=1;i<=n;i++) scanf("%d",&dfs[i]),dfn[dfs[i]]=i;
		deep[bfs[1]]=1;
		deep[bfs[2]]=2;
		for (i=3;i<=n;i++) {
			deep[bfs[i]]=deep[bfs[i-1]];
			if (dfn[bfs[i]] < dfn[bfs[i-1]] || (dfn[bfs[i]]==dfn[bfs[i-1]]+1 && bfs[i]<bfs[i-1])) deep[bfs[i]]++;
		}
		for (i=2;i<=n;i++) {
			for (j=i-1;j;j--) {
				if (deep[dfs[j]] < deep[dfs[i]]) {
					current=(Node *)malloc(sizeof(Node));
					current->next=NULL;
					current->child=dfs[i];
					if (tree[dfs[j]].next!=NULL) {
						for (ptr=tree[dfs[j]].next;ptr->next!=NULL;ptr=ptr->next);
						ptr->next=current;
					}
					else tree[dfs[j]].next=current;
					break;
				}
			}
		}
		for (i=1;i<=n;i++) {
			printf("%d:",i);
			for (ptr=tree[i].next;ptr!=NULL;ptr=ptr->next) printf(" %d",ptr->child);
			puts("");
		}
	}
}