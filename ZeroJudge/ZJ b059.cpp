#include <iostream>
using namespace std;

int main() {
	bool ox[100][100];
	int a[100][100],n,i,j,px[10001],py[10001];
	while (cin>>n) {
		memset(a,0,sizeof(a));
		memset(ox,1,sizeof(ox));
		for (;n;n--) {
			cin>>i>>j;
			a[i][j]=-1,ox[i][j]=0;
		}
		cin>>px[0]>>py[0]>>px[10000]>>py[10000];
		ox[px[0]][py[0]]=0;
		for (i=j=0;i<=j;i++) {
			if (a[px[i]+1][py[i]]>=0) {
				if (px[i]+3<100) {
					if (py[i]+1<100) {
						if (ox[px[i]+3][py[i]+1]) {
							j++;
							px[j]=px[i]+3,py[j]=py[i]+1;
							a[px[i]+3][py[i]+1]=a[px[i]][py[i]]+1;
							ox[px[i]+3][py[i]+1]=0;
						}
					}
					if (py[i]-1>=0) {
						if (ox[px[i]+3][py[i]-1]) {
							j++;
							px[j]=px[i]+3,py[j]=py[i]-1;
							a[px[i]+3][py[i]-1]=a[px[i]][py[i]]+1;
							ox[px[i]+3][py[i]-1]=0;
						}
					}
				}
			}
			if (a[px[i]-1][py[i]]>=0) {
				if (px[i]-3>=0) {
					if (py[i]+1<100) {
						if (ox[px[i]-3][py[i]+1]) {
							j++;
							px[j]=px[i]-3,py[j]=py[i]+1;
							a[px[i]-3][py[i]+1]=a[px[i]][py[i]]+1;
							ox[px[i]-3][py[i]+1]=0;
						}
					}
					if (py[i]-1>=0) {
						if (ox[px[i]-3][py[i]-1]) {
							j++;
							px[j]=px[i]-3,py[j]=py[i]-1;
							a[px[i]-3][py[i]-1]=a[px[i]][py[i]]+1;
							ox[px[i]-3][py[i]-1]=0;
						}
					}
				}
			}
			if (a[px[i]][py[i]+1]>=0) {
				if (py[i]+3<100) {
					if (px[i]+1<100) {
						if (ox[px[i]+1][py[i]+3]) {
							j++;
							px[j]=px[i]+1,py[j]=py[i]+3;
							a[px[i]+1][py[i]+3]=a[px[i]][py[i]]+1;
							ox[px[i]+1][py[i]+3]=0;
						}
					}
					if (px[i]-1>=0) {
						if (ox[px[i]-1][py[i]+3]) {
							j++;
							px[j]=px[i]-1,py[j]=py[i]+3;
							a[px[i]-1][py[i]+3]=a[px[i]][py[i]]+1;
							ox[px[i]-1][py[i]+3]=0;
						}
					}
				}
			}
			if (a[px[i]][py[i]-1]>=0) {
				if (py[i]-3>=0) {
					if (px[i]+1<100) {
						if (ox[px[i]+1][py[i]-3]) {
							j++;
							px[j]=px[i]+1,py[j]=py[i]-3;
							a[px[i]+1][py[i]-3]=a[px[i]][py[i]]+1;
							ox[px[i]+1][py[i]-3]=0;
						}
					}
					if (px[i]-1>=0) {
						if (ox[px[i]-1][py[i]-3]) {
							j++;
							px[j]=px[i]-1,py[j]=py[i]-3;
							a[px[i]-1][py[i]-3]=a[px[i]][py[i]]+1;
							ox[px[i]-1][py[i]-3]=0;
						}
					}
				}
			}
			if (ox[px[10000]][py[10000]]==0) break;
		}
		if (a[px[10000]][py[10000]]) cout<<a[px[10000]][py[10000]]<<endl;
		else cout<<"impossible\n";
	}
}