#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
typedef struct list List;
struct node{
	int value;
	Node *next;
};
struct list{
	Node *head,*tail;
	int num;
};
int n;
List L;
int input() {
	int entry;
	char ch;
	Node *ptr;
	if (scanf("%d%c",&n,&ch)==EOF) return 0;
	L.num=0;
	while (L.head) {
		ptr=L.head;
		L.head=L.head->next;
		free(ptr);
	}
	L.tail=NULL;
	while (scanf("%d%c",&entry,&ch)!=EOF) {
		ptr=(Node *)malloc(sizeof(Node));
		ptr->value=entry;
		ptr->next=NULL;
		if (L.tail) L.tail->next=ptr;
		L.tail=ptr;
		if (!(L.head)) L.head=ptr;
		L.num++;
		if (ch=='\n') return 1;
	}
	return 0;
}
void output() {
	int sum=0,m;
	Node *ptr;
	for (m=L.num-1,ptr=L.head;m;ptr=ptr->next,m--) sum=(ptr->value)*m+sum*n;
	printf("%d\n",sum);
	return;
}
int main() {
	while (input()) output();
}