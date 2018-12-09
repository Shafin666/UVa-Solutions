#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
typedef long long ll;
typedef long double ld;
using namespace std;

int par[30005], cnt[30005];

void init() { for(int i = 1; i <= 30005; i++) par[i] = i, cnt[i] = 0; }

int find(int x) {return (x == par[x])? par[x] : find(par[x]);}
void join(int a, int b) {par[find(b)] = find(a);}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int tc, n, m;
	int i, x, y;

	cin >> tc;
	while(tc--) {
		int mx = -1;

		init();
		cin >> n >> m;
		for(i = 0; i < m; i++) {
			cin >> x >> y;
			if(find(x) != find(y)) join(x, y);
		}

		for(i = 1; i <= n; i++) cnt[find(i)]++, mx = max(mx, cnt[find(i)]);
		cout << mx << endl;
	}
    return 0;
}
