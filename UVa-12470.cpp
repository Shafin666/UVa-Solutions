#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;
using matrix = vector<vector<ll>>;

const ll mod = 1e9+9;

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
	
	matrix T(3, vector<ll>(3)), F(3, vector<ll>(1));
	ll n, i, j;


	for(i = 2; i > -1; i--) T[2][i] = 1;
	for(i = 0; i < 2; i++) T[i][i+1] = 1;
	for(i = 0; i < 3; i++) F[i][0] = i;

	while(cin >> n && n) {
		if(n <= 3) { cout << n-1 << endl; continue; }

		matrix pow_T = pow(T, n-3);
		matrix Fn = multiply(pow_T, F);

		cout << Fn[2][0] << endl;
	}

    return 0;
}
