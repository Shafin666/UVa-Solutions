#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll n = 3;
ll m;

void multiply(ll a[n][n], ll b[n][n]) {
	ll mul[n][n], i, j, k;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			mul[i][j] = 0;
			for(k = 0; k < n; k++) mul[i][j] = (mul[i][j] + (a[i][k]*b[k][j]) % m) % m;
		}
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) a[i][j] = mul[i][j];
	}
}

ll power(ll f[n][n], ll N) {
	ll M[3][3] = {{1, 1, 1},
		      {1, 0, 0},
		      {0, 0, 1}};

	if(N == 1) return (f[0][0] + f[0][1] + f[0][2]) % m;
	power(f, N/2);
	multiply(f, f);

	if(N & 1) multiply(f, M);
	return (f[0][0] + f[0][1] + f[0][2]) % m;
}

ll find(ll n) {
	ll M[3][3] = {{1, 1, 1},
		      {1, 0, 0},
		      {0, 0, 1}};
	return power(M, n-1);
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	ll n, caseno = 0;

	while(scanf("%lld %lld", &n, &m) && (n || m)) {
		if(n == 0 || n == 1) { printf("Case %lld: %lld %lld %lld\n", ++caseno, n, m, 1 % m); continue; }
		printf("Case %lld: %lld %lld %lld\n", ++caseno, n, m, find(n));
	}	
    return 0;
}
