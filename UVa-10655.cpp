#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;
using matrix = vector<vector<ll>>;

const ll mod = 9223372036854775807;

matrix multiply(matrix a, matrix b) {
	matrix c(a.size(), vector<ll>(b[0].size()));
	for(ll i = 0; i < (ll)a.size(); i++)
		for(ll j = 0; j < (ll)b[0].size(); j++) 
			for(ll k = 0; k < (ll)a.size(); k++)
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
	return c;
}
matrix pow(matrix a, ll b) {
	if(b == 1) return a;
	matrix x = pow(a, b/2);
	x = multiply(x, x);
	if(b & 1) x = multiply(x, a);
	return x;
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	ll p, q, n;

	while(scanf("%lld%lld%lld", &p, &q, &n) == 3) {

		if(!n) { printf("2\n"); continue; }
		if(n == 1) { printf("%lld\n", p); continue; }

		matrix T(2, vector<ll>(2));
		matrix F(2, vector<ll>(1));

		T[0][0] = 0; T[0][1] = 1; 		F[0][0] = 2;
		T[1][0] = -q; T[1][1] = p;		F[1][0] = p;

		matrix pow_T = pow(T, n-1);
		matrix Fn = multiply(pow_T, F);

		
		printf("%lld\n", Fn[1][0]);
	}

    return 0;
}
