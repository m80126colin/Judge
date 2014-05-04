#include <stdio.h>
#include <stdlib.h>
typedef struct people Peo;
struct people{
	int number;
	Peo *next;
};
int main() {
	int n,i;
	Peo *jose,*previous,*head;
	scanf("%d",&n);
	previous=head=NULL;
	for (i=0;i<n;i++) {
		jose=(Peo *)malloc(sizeof(Peo));
		jose->number=n-i;
		if (i==0) head=jose;
		jose->next=previous;
		previous=jose;
		if (i==n-1) head->next=jose;
	}
	while (jose->next!=jose) {
		Peo *ptr=jose->next;
		jose->next=jose->next->next;
		free(ptr);
		jose=jose->next;
	}
	printf("%d\n",jose->number);
}