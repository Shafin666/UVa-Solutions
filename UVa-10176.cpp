#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll m = 131071;

ll bigmod(ll a, ll b, ll m) {
	if(!b) return 1 % m;
	ll x = bigmod(a, b/2, m);
	x = (x * x) % m;
	if(b & 1) x = (x * a) % m;
	return x;
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	string str;
	ll n, i, j;

	while(cin >> str) {
		while(str[str.length()-1] != '#') {
			string str1;
			cin >> str1; str += str1;
		}
		ll mod = 0;

		reverse(str.begin(), str.end());

		n = str.length();
		for(i = 1, j = 0; i < n; i++, j++) {
			if(str[i] == '1') mod = (mod + bigmod(2, j, m)) % m;
		}

		puts((!mod)? "YES" : "NO");
	}
    return 0;
}
