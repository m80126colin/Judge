#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node{
	int value;
	Node *next;
};
Node *head,*tail;
int input() {
	char ch;
	int entry;
	Node *current;
	head=tail=NULL;
	while (scanf("%d%c",&entry,&ch)!=EOF) {
		current=(Node *)malloc(sizeof(Node));
		current->value=entry;
		current->next=NULL;
		if (tail) tail->next=current;
		tail=current;
		if (!head) head=current;
		if (ch=='\n') return 1;
	}
	return 0;
}
void output() {
	int entry,sum;
	char ch;
	Node *ptr;
	while (scanf("%d%c",&entry,&ch)!=EOF) {
		for (sum=0,ptr=head;ptr!=NULL;ptr=ptr->next) sum=ptr->value+sum*entry;
		printf("%d%c",sum,ch);
		if (ch=='\n') return;
	}
	return;
}
int main() {
	while (input()) output();
}