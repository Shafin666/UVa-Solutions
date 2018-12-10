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
	ll n, q, tc, c = 0;
	ll num[60005], upd[60005];;

	cin >> tc;
	while(tc--) {
		ll k = 0, mx = 2e9+15;

		cin >> n >> q;
		for(ll i = 0; i < n; i++) cin >> num[i];
		for(ll i = 0; i < q; i++) cin >> upd[i];
		
		if(c++) cout << endl;

		M.insert(mx);
		multiset<ll> :: iterator it = M.begin();

		for(ll i = 0; i < q; i++) {
			while(k < upd[i]) {
				if(num[k] < *it) M.insert(num[k++]), it--;
				else M.insert(num[k++]);
			}
			cout << *it++ << endl;
		} M.clear();
	}
    return 0;
}
