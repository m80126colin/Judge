#include <stdio.h>
int n, p[8];
inline void var() {
	int i;
	for (i = 0; i < n; i++) {
		putchar('a' + i);
		if (i + 1 < n) putchar(',');
	}
}
inline void var2() {
	int i;
	for (i = 0; i < n; i++) {
		putchar('a' + p[i]);
		if (i + 1 < n) putchar(',');
	}
}
inline void indent(int x) {
	int i;
	for (i = 0; i < x; i++) {
		putchar(' ');
		putchar(' ');
	}
}
inline void print_sort(int x) {
	int i;
	if (x == n) {
		indent(x);
		printf("writeln(");
		var2();
		puts(")");
		return;
	}
	p[x] = x;
	for (i = x; i; i--) {
		p[i] = x;
		indent(x);
		if (i == x) printf("if %c < %c then\n", 'a' + p[i-1], 'a' + p[i]);
		else printf("else if %c < %c then\n", 'a' + p[i-1], 'a' + p[i]);
		print_sort(x+1);
		p[i] = p[i-1];
	}
	p[0] = x;
	if (x) {
		indent(x);
		puts("else");
	}
	print_sort(x+1);
	for (i = 0; i < x; i++) p[i] = p[i+1];
	return;
}
int main() {
	int t;
	for (scanf("%d",&t); t; t--) {
		scanf("%d",&n);
		puts("program sort(input,output);\nvar");
		var();
		printf(" : integer;\nbegin\n  readln(");
		var();
		puts(");");
		print_sort(0);
		puts("end.");
		if (t>1) puts("");
	}
}

/*
program sort(input,output);
var
a,b,c : integer;
begin
  readln(a,b,c);
  if a < b then
    if b < c then
      writeln(a,b,c)
    else if a < c then
      writeln(a,c,b)
    else
      writeln(c,a,b)
  else
    if a < c then
      writeln(b,a,c)
    else if b < c then
      writeln(b,c,a)
    else
      writeln(c,b,a)
end.
*/