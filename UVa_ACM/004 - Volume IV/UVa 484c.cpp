#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node{
	int value,time;
	Node *next;
};
int main() {
	int entry;
	Node *head,*tail,*ptr;
	head=tail=NULL;
	while (scanf("%d",&entry)!=EOF) {
		for (ptr=head;ptr!=NULL;ptr=ptr->next) {
			if (ptr->value==entry) {
				ptr->time++;
				break;
			}
		}
		if (ptr!=NULL) continue;
		ptr=(Node *)malloc(sizeof(Node));
		ptr->value=entry;
		ptr->time=1;
		ptr->next=NULL;
		if (tail) tail->next=ptr;
		tail=ptr;
		if (!head) head=ptr;
	}
	for (ptr=head;ptr!=NULL;ptr=ptr->next) printf("%d %d\n",ptr->value,ptr->time);
}