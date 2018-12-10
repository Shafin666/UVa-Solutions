#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;
using matrix = vector<vector<ll>>;

ll mod;

matrix mul(matrix a, matrix b) {
	matrix C(a.size(), vector<ll>(b[0].size()));
	for(ll i = 0; i < a.size(); i++)
		for(ll j = 0; j < b[0].size(); j++)
			for(ll k = 0; k < a.size(); k++)
				C[i][j] = (C[i][j] + (a[i][k]*b[k][j]) % mod) % mod;
	return C;
}
matrix power(matrix a, ll n) {
	if(n == 1) return a;
	matrix x = power(a, n/2);
	x = mul(x, x);
	if(n & 1) x = mul(x, a);
	return x;
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	ll d, n;
	ll i, j;

	while(cin >> d >> n >> mod && (d || n || mod)) {
		matrix T(d, vector<ll>(d));
		matrix F(d, vector<ll>(1));

		for(i = d-1; i > -1; i--) cin >> T[d-1][i];
		for(i = 0; i < d; i++) cin >> F[i][0];
		for(i = 0; i < d-1; i++) T[i][i+1] = 1;

		if(n <= d) printf("%lld\n", F[n-1][0] % mod);
		else {
			matrix Power_T = power(T, n-d);
			matrix Fn = mul(Power_T, F);

			printf("%lld\n", Fn[d-1][0] % mod);
		}
	}
    return 0;
}
