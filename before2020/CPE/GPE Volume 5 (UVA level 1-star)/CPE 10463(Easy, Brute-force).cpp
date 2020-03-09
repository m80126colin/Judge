/**
 *  @judge CPE
 *  @id 10463
 *  @source UVa 10994
 * 
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int i, j, n, ans;
    while (cin >> i >> j)
    {
        if (i < 0 && j < 0)
        break;
        if (i > j) swap(i, j);
        ans = 0;
        for (; i <= j; i++)
         {
             n = i;
             while (!(n % 10)) n /= 10;
             ans += n % 10;
         }
         printf("%d\n", ans);
    }
}