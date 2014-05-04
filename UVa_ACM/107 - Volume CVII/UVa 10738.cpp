#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	static bool pr[1000000];
	static long long p[100001],i,j,mu[1000001],m[1000001];
	memset(pr,1,sizeof(pr));
	pr[1]=0;
	p[0]=0;
	for (i=1;i<1000;i++) {
		if (pr[i]) {
			p[0]++;
			p[p[0]]=i;
			for (j=1;j*i<1000000;j++) pr[j*i]=0;
		}
	}
	for (i=1000;i<1000000;i++) {
		if (pr[i]) {
			p[0]++;
			p[p[0]]=i;
		}
	}
	memset(mu,0,sizeof(mu));
	mu[1]=1,m[1]=1;
	for (int x1=1;x1<=p[0];x1++) mu[p[x1]]=-1;
	for (int x1=1;x1<=170;x1++) {
		for (int x2=x1+1;;x2++) {
			if (p[x1]*p[x2]>1000000) break;
			mu[p[x1]*p[x2]]=1;
		}
	}
	for (int x1=1;x1<=170;x1++) {
		for (int x2=x1+1;;x2++) {
			if (p[x1]*p[x2]>1000000) break;
			for (int x3=x2+1;;x3++) {
				if (p[x1]*p[x2]*p[x3]>1000000) break;
				mu[p[x1]*p[x2]*p[x3]]=-1;
			}
		}
	}
	for (int x1=1;x1<=170;x1++) {
		for (int x2=x1+1;;x2++) {
			if (p[x1]*p[x2]>1000000) break;
			for (int x3=x2+1;;x3++) {
				if (p[x1]*p[x2]*p[x3]>1000000) break;
				for (int x4=x3+1;;x4++) {
					if (p[x1]*p[x2]*p[x3]*p[x4]>1000000) break;
					mu[p[x1]*p[x2]*p[x3]*p[x4]]=1;
				}
			}
		}
	}
	for (int x1=1;x1<=170;x1++) {
		for (int x2=x1+1;;x2++) {
			if (p[x1]*p[x2]>1000000) break;
			for (int x3=x2+1;;x3++) {
				if (p[x1]*p[x2]*p[x3]>1000000) break;
				for (int x4=x3+1;;x4++) {
					if (p[x1]*p[x2]*p[x3]*p[x4]>1000000) break;
					for (int x5=x4+1;;x5++) {
						if (p[x1]*p[x2]*p[x3]*p[x4]*p[x5]>1000000) break;
						mu[p[x1]*p[x2]*p[x3]*p[x4]*p[x5]]=-1;
					}
				}
			}
		}
	}
	for (int x1=1;x1<=170;x1++) {
		for (int x2=x1+1;;x2++) {
			if (p[x1]*p[x2]>1000000) break;
			for (int x3=x2+1;;x3++) {
				if (p[x1]*p[x2]*p[x3]>1000000) break;
				for (int x4=x3+1;;x4++) {
					if (p[x1]*p[x2]*p[x3]*p[x4]>1000000) break;
					for (int x5=x4+1;;x5++) {
						if (p[x1]*p[x2]*p[x3]*p[x4]*p[x5]>1000000) break;
						for (int x6=x5+1;;x6++) {
							if (p[x1]*p[x2]*p[x3]*p[x4]*p[x5]*p[x6]>1000000) break;
							mu[p[x1]*p[x2]*p[x3]*p[x4]*p[x5]*p[x6]]=1;
						}
						
					}
				}
			}
		}
	}
	for (int x1=1;x1<=170;x1++) {
		for (int x2=x1+1;;x2++) {
			if (p[x1]*p[x2]>1000000) break;
			for (int x3=x2+1;;x3++) {
				if (p[x1]*p[x2]*p[x3]>1000000) break;
				for (int x4=x3+1;;x4++) {
					if (p[x1]*p[x2]*p[x3]*p[x4]>1000000) break;
					for (int x5=x4+1;;x5++) {
						if (p[x1]*p[x2]*p[x3]*p[x4]*p[x5]>1000000) break;
						for (int x6=x5+1;;x6++) {
							if (p[x1]*p[x2]*p[x3]*p[x4]*p[x5]*p[x6]>1000000) break;
							for (int x7=x6+1;;x7++) {
								if (p[x1]*p[x2]*p[x3]*p[x4]*p[x5]*p[x6]*p[x7]>1000000) break;
								mu[p[x1]*p[x2]*p[x3]*p[x4]*p[x5]*p[x6]*p[x7]]=-1;
							}
						}
						
					}
				}
			}
		}
	}
	for (i=2;i<=1000000;i++) m[i]=m[i-1]+mu[i];
	for (cin>>i;i;cin>>i) cout<<fixed<<setw(8)<<i<<setw(8)<<mu[i]<<setw(8)<<m[i]<<endl;
}