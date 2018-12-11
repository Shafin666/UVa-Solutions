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

	int tc, n;
	int dp[55];

	cin >> tc;
	while(tc--) {
		int i, j;

		cin >> n;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;

		for(i = 2; ;i++) {
			for(j = 0; j < n; j++) {
				int tmp = dp[j]+i;
				tmp = (int)sqrt(tmp);

				if(tmp*tmp == dp[j]+i || !dp[j]) {
					dp[j] = i;
					break;
				}
			} if(j == n) break;
		}
		cout << i-1 << endl;
	}
    return 0;
}
