/*
Problem: d575(fast)
Language: C++
Result: AC (35ms, 645KB) on ZeroJudge
Author: m80126colin at 2010-07-12 16:42:24
Solution: Math
*/
#import <iostream>
#define A long long
A a,b,c,d,e,f,r;
inline bool z(A& g) {  //input optimization
	while ((f=getchar())==32||f==10);
	for (g=(e=f-'-')?f-48:0;++f&&(f=getchar())-32&&f-10;g=g*10+(e?f-48:48-f));
	return f;
}
inline A y(A x) {return (x>0)?x:-x;}  //abs
main() {for (;z(a)&z(b)&z(c)&z(d)&z(r);puts((y(c-a)+y(d-b)>r?"alive":"die")));}