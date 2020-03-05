#include <stdio.h>
typedef struct company Company;
struct company{
	char name[80];
	int option;
	double price;
};
int main() {
	int n,p,i,j,ctr;
	char ch[80];
	Company comp[1000],maxnum;
	for (ctr=1;scanf("%d%d",&n,&p)&&(n!=0&&p!=0);ctr++) {
		if (ctr>1) puts("");
		for (i=0;i<=n;i++) gets(ch);
		for (i=0;i<p;i++) {
			gets(comp[i].name);
			scanf("%lf%d",&comp[i].price,&comp[i].option);
			for (j=0;j<=comp[i].option;j++) gets(ch);
		}
		maxnum=comp[0];
		for (i=1;i<p;i++) {
			if (comp[i].option>maxnum.option) maxnum=comp[i];
			else if (comp[i].option==maxnum.option&&comp[i].price<maxnum.price) maxnum=comp[i];
		}
		printf("RFP #%d\n%s\n",ctr,maxnum.name);
	}
}