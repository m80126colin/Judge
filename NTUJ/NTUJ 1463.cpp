#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct gt
{
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

int n, rcd[101];
stack <int> stk;
queue <int> quu;
priority_queue <int, vector<int>, gt> puu;
bool oxs, oxq, oxp;

inline void init()
{
	int i;
	for (i = 0; i < 101; i++) rcd[i] = 0;
	while (!stk.empty()) stk.pop();
	while (!quu.empty()) quu.pop();
	while (!puu.empty()) puu.pop();
	oxs = oxq = oxp = 1;
}

inline void push(int ele)
{
	rcd[ele]++;
	stk.push(ele);
	quu.push(ele);
	puu.push(ele);
}

inline void noa()
{
	oxs = oxq = oxp = 0;
}

void pop(int ele)
{
	if (ele <= 0 || ele > 100 || rcd[ele] <= 0) 
	{
		noa();
		return;
	}
	rcd[ele]--;
	if (oxs)
	{
		if (stk.top() != ele) oxs = 0;
		else stk.pop();
	}
	if (oxq)
	{
		if (quu.front() != ele) oxq = 0;
		else quu.pop();
	}
	if (oxp)
	{
		if (puu.top() != ele) oxp = 0;
		else puu.pop();
	}
	return;
}

int main()
{
	int i, com, ele, ans;
	while (scanf("%d", &n) != EOF)
	{
		init();
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &com, &ele);
			if (com & 1) push(ele);
			else pop(ele);
		}
		ans = oxs + oxq + oxp;
		if (ans > 1) puts("not sure");
		else if (!ans) puts("impossible");
		else if (oxs) puts("stack");
		else if (oxq) puts("queue");
		else puts("priority queue");
	}
}