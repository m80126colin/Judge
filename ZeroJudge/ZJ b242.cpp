#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

struct node{
	long long num, way;
	node() {}
	node(long long num, long long way): num(num), way(way){}
};

int main() {
	long long n, t, i, ans, pn;
	node tmp;
	stack <node> s;
	for (scanf("%lld", &t); t ; t--) {
		scanf("%lld", &n);
		while (!s.empty()) s.pop();
		ans = 0;
		for (i = 0; i < n; i++)
		{
			pn = 0;
			scanf("%lld", &tmp.num);
			tmp.way = 1;
			while (!s.empty() && s.top().num < tmp.num) {
				pn += s.top().way;
				s.pop();
			}
			ans += pn;
			if (!s.empty()) 
			{
				if (s.top().num == tmp.num) {
					tmp.way += s.top().way;
					ans += s.top().way;
					s.pop();
				}
				if (!s.empty()) ans++;
			}
			s.push(tmp);
		}
		printf("%lld\n", ans);
	}
}