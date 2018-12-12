#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1005;
int lp[N+1], dp[N+1];
vector<int> pr;

void linsieve() {
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}
int sod(int m) {
	if(m == 1) return 1;
	if(dp[m] != -1) return dp[m];

	int k = lp[m], ans, n = m, cnt = 0;
	while(n % k == 0) n /= k, cnt++;
	ans = (pow(k, cnt+1)-1)/(k-1);

	return dp[m] = ans * sod(n);
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	linsieve(); memset(dp, -1, sizeof dp);

	int s, caseno = 0;
	
	while(cin >> s && s) {
		int f = 0;
		for(int i = 1000; i >= 1; i--) if(sod(i) == s) {printf("Case %d: %d\n", ++caseno, i); f = 1; break;}
		if(!f) printf("Case %d: -1\n", ++caseno);
	}

    return 0;
}
