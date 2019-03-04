#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;

int a[1005], pre[2005];
int dp[2005][2005], mid[2005][2005];

int main() 
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, i, j;

	while(cin >> n) {
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];


		for(int i = 0; i <= n; i++) mid[i][i] = i;

		for(int dis = 1; dis < n; dis++) {
			for(int i = 1; i <= n-dis; i++) {
				int j = i + dis;
				int cost = pre[j] - pre[i-1];

				dp[i][j] = 1e9+7;
				for(int k = mid[i][j-1]; k <= mid[i+1][j]; k++) {
					if (dp[i][k - 1] + dp[k + 1][j] + cost - a[k] < dp[i][j]) {
                        dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + cost - a[k];
                        mid[i][j] = k;
					}
				}
			}
		}
		cout << dp[1][n] << endl;
	}
	return 0;
}
