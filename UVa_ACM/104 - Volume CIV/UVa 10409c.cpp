#include <stdio.h>
#include <string.h>
int dice[6];
void init() {
	dice[0]=1;
	dice[1]=2;
	dice[2]=3;
	dice[3]=5;
	dice[4]=4;
	dice[5]=6;
	return;
}
void north() {
	int temp;
	temp=dice[0];
	dice[0]=dice[3];
	dice[3]=dice[5];
	dice[5]=dice[1];
	dice[1]=temp;
	return;
}
void south() {
	int temp;
	temp=dice[1];
	dice[1]=dice[5];
	dice[5]=dice[3];
	dice[3]=dice[0];
	dice[0]=temp;
	return;
}
void east() {
	int temp;
	temp=dice[0];
	dice[0]=dice[2];
	dice[2]=dice[5];
	dice[5]=dice[4];
	dice[4]=temp;
	return;
}
void west() {
	int temp;
	temp=dice[4];
	dice[4]=dice[5];
	dice[5]=dice[2];
	dice[2]=dice[0];
	dice[0]=temp;
	return;
}
int main() {
	int n;
	char s[6];
	while (scanf("%d",&n),n) {
		init();
		while (n--) {
			scanf("%s",s);
			if (strcmp(s,"north")==0) north();
			else if (strcmp(s,"south")==0) south();
			else if (strcmp(s,"east")==0) east();
			else if (strcmp(s,"west")==0) west();
		}
		printf("%d\n",dice[0]);
	}
}