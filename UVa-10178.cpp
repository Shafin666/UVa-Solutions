#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;

bool check[265];
int plc[256];
int par[256];

int find(int x) { return (par[x] == x)? par[x] : find(par[x]); }
void join(int a, int b) { par[find(b)] = find(a); }
void init() { for(int i = 1; i <= 256; i++) par[i] = i; memset(check, 0, sizeof check); }

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int n, m;
	char p, q;

	while(cin >> n >> m) {
		int cnt = 0; init();
		set<int> s;

		for(int i = 0; i < m; i++) {
			cin >> p >> q;

			if(!check[p]) plc[p] = ++cnt;
			if(!check[q]) plc[q] = ++cnt;
			check[p] = check[q] = 1;

			if(find(plc[p]) != find(plc[q])) join(plc[p], plc[q]);
		}
		for(int i = 1; i <= n; i++) s.insert(find(i));
		int k = s.size(); s.clear();

		cout << m-n+k+1 << endl;
	}
    return 0;
}
