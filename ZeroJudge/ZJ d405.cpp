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
              if (a>n||b>s[a][0]||!b||!a) cout<<"��!!!�ۿ���"<<i<<"���k�ͪ��Z�Ůy���F��!!\n";
              else if (s[a][b]>=90&&s[a][b]<=100) cout<<"��"<<i<<"���k��  ��"<<a<<"�Z����"<<b<<"��  ���Z��"<<s[a][b]<<" ���Z�u\n";
              else if (s[a][b]>=60&&s[a][b]<90) cout<<"��"<<i<<"���k��  ��"<<a<<"�Z����"<<b<<"��  ���Z��"<<s[a][b]<<endl;
              else  cout<<"��"<<i<<"���k��  ��"<<a<<"�Z����"<<b<<"��  ���Z��"<<s[a][b]<<" ���ή�r~~\n";
              }
          }
    }
