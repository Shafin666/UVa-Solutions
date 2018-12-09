#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
typedef long long ll;
typedef long double ld;
using namespace std;

struct BinaryIndexedTree {
	int a[200002];
	int maxn = 200000;

	void init() {
		memset(a, 0, sizeof(a));
	}

	void add(int idx, int v) {
		while(idx <= maxn) {
			a[idx] += v;
			idx += (idx & (-idx));
		}
	}
	int sum(int idx) {
		int ret = 0;
		while(idx) {
			ret += a[idx];
			idx -= (idx & (-idx));
		} return ret;
	}
} BIT;

int main()
{	
	//freopen("in.txt", "r", stdin);

	int n, caseno = 0;
	int i, j, k;
	char ch, str[10]; 

	while(scanf("%d", &n) && n) {

		BIT.init();
		for(i = 0; i < n; i++) {
			scanf("%d", &k);
			BIT.add(i+1, k);
		}
		if(caseno) printf("\n");
		getchar();
		printf("Case %d:\n", ++caseno);
		
		while(scanf("%c", &ch) && ch != 'E') {
			scanf("%d%d", &i, &j); getchar();
			if(ch == 'S') BIT.add(i, j-(BIT.sum(i) - BIT.sum(i-1)));
			else printf("%d\n", BIT.sum(j)-BIT.sum(i-1));
		} gets(str);
	}
    return 0;
}
