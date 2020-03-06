/**
 *  @judge UVa
 *  @id 409
 *  @tag Simple, String Manipulation
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#define N 30
using namespace std;

char key[N][50], tmkey[N][50], excuse[N][100], tmp[N][100];
int tim[N], mx;

inline void toLower(char *str, char *dest)
{
	int i, j, len;
	len = strlen(str);
	for (i = j = 0; i < len; i++)
		if (isalpha(str[i])) dest[j++] = tolower(str[i]);
		else dest[j++] = ' ';
	dest[j] = '\0';
	return;
}

inline int mysubstr(char *dest, char *str)
{
	int len = strlen(dest), slen = strlen(str);
	if (len < slen) return 0;
	int i;
	for (i = 0; i < slen; i++)
		if (dest[i] != str[i]) return 0;
	if (dest[slen] == ' ' || dest[slen] == '\0') return 1;
	return 0;
}

inline int isexcuse(char *str, char *dest)
{
	int cnt = 0, i, len;
	len = strlen(dest);
	for (i = 0; i < len; i++)
		if (i == 0 || dest[i - 1] == ' ') cnt += mysubstr(dest + i, str);
	return cnt;
}

int main()
{
	//freopen("UVa_409.txt", "w+", stdout);
	int cnt, k, e, i, j;
	for (cnt = 1; cin >> k >> e; cnt++)
	{
		for (i = 0; i < k; i++)
		{
			scanf("%s", key[i]);
			toLower(key[i], tmkey[i]);
		}
		cin.ignore(1);
		//if (cnt > 1) puts("");
		printf("Excuse Set #%d\n", cnt);
		memset(tim, 0, sizeof(tim));
		mx = 0;
		for (j = 0; j < e; j++)
		{
			fgets(excuse[j], 99, stdin);
			toLower(excuse[j], tmp[j]);
			for (i = 0; i < k; i++) tim[j] += isexcuse(tmkey[i], tmp[j]);
			if (tim[j] > mx) mx = tim[j];
		}
		for (j = 0; j < e; j++)
			if (tim[j] == mx) printf("%s", excuse[j]);
		puts("");
	}
}