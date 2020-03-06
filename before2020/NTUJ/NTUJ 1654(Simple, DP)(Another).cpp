/**
 *  @judge NTUJ
 *  @id 1654
 *  @tag Simple, DP
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 510
int t, r, c;
int s[MAX][MAX], m[MAX][MAX], p[MAX][MAX];

int trial(int middle)
{
    memset(m, 0, sizeof(m));
    memset(p, 0, sizeof(p));
    int i, j;
	for (i = 2; i <= r; i++) p[i][0] = 1;
	for (j = 2; j <= r; j++) p[0][j] = 1;
    m[0][1] = m[1][0] = middle;
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
        {
            if (p[i - 1][j] && p[i][j - 1]) p[i][j] = 1;
            else if (p[i - 1][j]) m[i][j] = m[i][j - 1] + s[i][j];
            else if (p[i][j - 1]) m[i][j] = m[i - 1][j] + s[i][j];
            else m[i][j] = max(m[i - 1][j], m[i][j - 1]) + s[i][j];
            if (m[i][j] <= 0) p[i][j] = 1;
        }
    if (p[r][c]) return 0;
    return 1;
}

int sol(int left, int right)
{
    if (left == right) return left;
    int middle = (left + right) / 2;
    if (trial(middle)) return sol(left, middle);
    return sol(middle + 1, right);
}

int main()
{
    int i, j;
    for (scanf("%d", &t); t; t--)
    {
        scanf("%d%d", &r, &c);
        memset(s, 0, sizeof(s));
        for (i = 1; i <= r; i++)
            for (j = 1; j <= c; j++)
                scanf("%d", &s[i][j]);
        printf("%d\n", sol(1, 2100000000));
    }
}