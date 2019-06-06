#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define nyan "(=^･ω･^=)"
#define read_input         freopen("in.txt","r", stdin)
#define print_output       freopen("out.txt","w", stdout)
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int maxn = 1000005;
struct BinaryIndexedTree {

	ordered_set bit[maxn];

	void insert(int x, int y) {
		for(int i = x; i < maxn; i += i & -i) {
			bit[i].insert({y, x});
		}
	}

	void remove(int x, int y) {
		for(int i = x; i < maxn; i += i & -i) {
			bit[i].erase({y, x});
		}
	}

	int query(int x, int y) {
		int ans = 0;
		for(int i = x; i ; i -= i & -i) {
			ans += bit[i].order_of_key({y+1, 0});
		} return ans;
	}

	int query_sub(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
	}
} b;

set<int> s[maxn];
int a[maxn], p[maxn];

int main()
{
	//read_input;
	//print_output;

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], s[a[i]].insert(i);
	for(int i = 1; i < maxn; i++) s[i].insert(0), s[i].insert(1e9+7);

	for(int i = 1; i <= n; i++) {
		auto it = s[a[i]].lower_bound(i);
		if(it == s[a[i]].begin()) p[i] = 0;
		else it = prev(it), p[i] = *it;
	}
	for(int i = 1; i <= n; i++) b.insert(i, p[i]);

	while(m--) {
		char ch;
		cin >> ch;

		if(ch == 'Q') {
			int l, r;
			cin >> l >> r; l++;
			cout << b.query_sub(l, 0, r, l-1) << endl;
		}

		else {
			int x, y;
			cin >> x >> y;
			x++; int yold = a[x];
			a[x] = y;

			auto it = s[yold].lower_bound(x);
			auto it_l = prev(it), it_r = next(it);
			b.remove(*it, *it_l); b.remove(*it_r, *it);
			b.insert(*it_r, *it_l);
			s[yold].erase(x);

			it = s[y].lower_bound(x);
			it_r = it, it_l = prev(it);
			b.remove(*it_r, *it_l);
			b.insert(x, *it_l); b.insert(*it_r, x);
			s[y].insert(x);
		}
	}
    return 0;
}
