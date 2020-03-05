#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int f[26], pos[26], len;
char s[102];

int abs (int x) {
    if (x < 0) return -x;
    return x;
    }

int ispos() {
    int i, ox = 0;
    for (i = 0; i < 26; i++) f[i] = 0;
    for (i = 0; i < len; i++) f[s[i] - 'a']++;
    for (i = 0; i < 26; i++) {
        if (f[i] & 1) {
                 if (ox) return 0;
                 ox = 1;
                 }
        }
    return 1;
}

int match(char ch, int i) {
    int j, t = ch - 'a';
    //puts("FUUUUUCKKKK");
    for (;pos[t] > i; pos[t]--) {
        //printf("pos[t] = %d\n", pos[t]);
        if (s[pos[t] - 1] == ch) {
                      for (j = pos[t] - 1; j < len - i; j++) s[j] = s[j + 1];
                      s[len - i - 1] = ch;
                      pos[t]--;
                      return abs((len - i - 1) - pos[t]);
                      }
        }
        return 0;
}

int main() {
    int t, i, ans;
    for (scanf("%d", &t); t; t--) {
        scanf("%s", s);
        len = strlen(s);
        ans = 0;
        //printf("%d\n", len);
        if (!ispos()) printf("Impossible\n");
        else {
             for (i = 0; i < 26; i++) pos[i] = len;
             for (i = 0; i < len / 2; i++) {
                 if ( (f[s[i] - 'a'] == 1) && i + 1 < len && s[i] != s[i + 1]) {
                            ans++;
                            swap(s[i], s[i+1]);
                            }
                 ans += match(s[i], i);
                 f[s[i] - 'a'] -= 2;
                 //printf(" ~ %s\n", s);
                 }
             printf("%d\n", ans);
             }
        }
    }
