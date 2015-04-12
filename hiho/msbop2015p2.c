//source here
#include <stdio.h>

int main() {
	int t,n,nn,index;
	int mod = 1000000000+7;
	long long p, ans;
	scanf("%d", &t);
	index = 0;
	while(t>0) {
		t--;
		scanf("%d", &n);
		nn = n;
		if (n%2 == 0) {
			p = (n/2) % mod;
			n = n%mod;
			p = (p*(n+1))%mod;
		} else {
			p = ((n+1)/2)%mod;
			n = n%mod;
			p = (p*n)%mod;
		}
		ans = (p*p)%mod;
		ans = (ans*p)%mod + mod - (ans*2*(n-1))%mod;
		ans = ans % mod;
		
		index++;
		printf("Case %d: %ld\n", index, ans);
		
		/*
		p=0; n = nn;
		for (int i=1; i<=n; i++) {
			p += i;
		}
		ans = p*p*(p-2*(n-1));
		printf("%ld\n", ans);
		*/
	}
	return 0;
}
