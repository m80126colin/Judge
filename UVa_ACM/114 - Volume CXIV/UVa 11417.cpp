#include <iostream>
using namespace std;

int GCD(int a, int b) {
   if (b)
      return GCD(b, a%b);
   else
      return a;
}

int main() {
   int i, j, N, G;
   while (cin >> N, N) {
      G=0;
      for(i=1;i<N;i++)
         for(j=i+1;j<=N;j++)
         {
            G+=GCD(i,j);
         }
      cout << G << endl;
   }
}

//�פJ�D�ةҵ����{���A�A�w�q GCD ��ƧY�i�C