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

	vector<int> m1, m2;
	int n, m, i;
	int x;

	while(cin >> n>> m && (n || m)) {

		for(i = 0; i < n; i++) cin >> x, m1.pb(x);
		for(i = 0; i < m; i++) cin >> x, m2.pb(x);

		int cnt = 0;
		for(vector<int> :: iterator it1 = m1.begin(), it2 = m2.begin(); it1 != m1.end() && it2 != m2.end();) {
			if(*it1 == *it2) cnt++, it1++, it2++;
			else if(*it1 > *it2) it2++;
			else it1++;
		}
		cout << cnt << endl;
		m1.clear(); m2.clear();
	}
    return 0;
}
