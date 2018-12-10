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
	ll n, i, x;

	while(scanf("%lld", &n) && n) {
		ll ans = 0;

		for(i = 0; i < n; i++) {
			scanf("%lld", &x);
			M.insert(x);
		}
		while(M.size() > 1) {
			ll ft = *(M.begin()); M.erase(M.begin());
			ll st = *(M.begin()); M.erase(M.begin());
			ans += ft+st;
			M.insert(ft+st);
		}

		printf("%lld\n", ans);
		M.clear();
	}
    return 0;
}
