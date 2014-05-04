#include <iostream>
using namespace std;

int main() {
    int n,k,i,j,a,b;
    static int s[50001][31];
    while (cin>>n,n) {
          for (i=1;i<=n;i++) {
              cin>>s[i][0];
              for (j=1;j<=s[i][0];j++) cin>>s[i][j];
              }
          cin>>k;
          for (i=1;i<=k;i++) {
              cin>>a>>b;
              if (a>n||b>s[a][0]||!b||!a) cout<<"啊!!!抄錯第"<<i<<"號女生的班級座號了啦!!\n";
              else if (s[a][b]>=90&&s[a][b]<=100) cout<<"第"<<i<<"號女生  第"<<a<<"班的第"<<b<<"號  成績為"<<s[a][b]<<" 成績優\n";
              else if (s[a][b]>=60&&s[a][b]<90) cout<<"第"<<i<<"號女生  第"<<a<<"班的第"<<b<<"號  成績為"<<s[a][b]<<endl;
              else  cout<<"第"<<i<<"號女生  第"<<a<<"班的第"<<b<<"號  成績為"<<s[a][b]<<" 不及格呀~~\n";
              }
          }
    }
