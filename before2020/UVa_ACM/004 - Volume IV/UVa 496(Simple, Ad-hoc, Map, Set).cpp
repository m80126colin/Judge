/**
 *  @judge UVa
 *  @id 496
 *  @tag Simple, Ad hoc, Map, Set
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Set
{
	vector <int> v;
	map <int, int> m;
	void clear()
	{
		v.clear();
		m.clear();
	}
	void push_back(const int &a)
	{
		v.push_back(a);
		m[a] = 1;
	}
	void pop_back()
	{
		int a = v[v.size() - 1];
		v.pop_back();
		m[a] = 0;
	}
	int size()
	{
		return v.size();
	}
	int operator [] (const int &a)
	{
		return v[a];
	}
	int find(const int &a)
	{
		return m[a];
	}
}A, B;

inline void clean()
{
	A.clear();
	B.clear();
	return;
}

inline int input()
{
	int tmp;
	while (scanf("%d", &tmp) != EOF)
	{
		A.push_back(tmp);
		if (cin.peek() == '\n') break;
	}
	while (scanf("%d", &tmp) != EOF)
	{
		B.push_back(tmp);
		if (cin.peek() == '\n') return 1;
	}
	return 0;
}

inline int subset(Set &X, Set &Y)
{
	int i;
	for (i = 0; i < X.size(); i++)
	{
		if (!Y.find(X[i])) return 0;
	}
	return 1;
}

inline int disjoint(Set &X, Set &Y)
{
	int i;
	for (i = 0; i < X.size(); i++)
		if (Y.find(X[i])) return 0;
	for (i = 0; i < Y.size(); i++)
		if (X.find(Y[i])) return 0;
	return 1;
}

int main()
{
	int a, b;
	for (clean(); input(); clean())
	{
		a = subset(A, B);
		b = subset(B, A);
		if (a && b) puts("A equals B");
		else if (a) puts("A is a proper subset of B");
		else if (b) puts("B is a proper subset of A");
		else if (disjoint(A, B)) puts("A and B are disjoint");
		else puts("I'm confused!");
	}
}