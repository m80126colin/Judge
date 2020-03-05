#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    int i, ans;
    while (cin >> s, s != "0")
    {
        ans = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (i & 1) ans += s[i] - '0';
            else ans -= s[i] - '0';
        }
        cout << s;;
        if (ans % 11) puts(" is not a multiple of 11.");
        else puts(" is a multiple of 11.");
    }
}