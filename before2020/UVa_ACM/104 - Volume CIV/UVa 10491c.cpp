#include <stdio.h>
int main() {
	double nshow,ncars,ncows;
	while (scanf("%lf%lf%lf",&ncows,&ncars,&nshow)!=EOF) printf("%.5lf\n",ncars*(ncows+ncars-1.0)/(ncows+ncars)/(ncows+ncars-nshow-1.0));
}