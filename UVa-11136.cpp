#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	multiset<ll> M;
	ll n, k, x;

	while(scanf("%lld", &n) && n) {
		ll ans = 0;

		for(ll i = 0; i < n; i++) {
			scanf("%lld", &k);
			while(k--) scanf("%lld", &x), M.insert(x);

			multiset<ll> :: iterator itlo = M.begin(), ithi = prev(M.end());

			ans += *(ithi)-*(itlo);
			M.erase(itlo); M.erase(ithi);
		}
		cout << ans << endl;
		M.clear();
	}
    return 0;
}
