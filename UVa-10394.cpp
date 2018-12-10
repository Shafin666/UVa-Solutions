#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 20000000;
int lp[N+1];
vector<int> pr, ans;

void lineral_sieve() {
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	lineral_sieve();
	int i, n;

	for(i = 1; i < (int) pr.size(); i++) if(pr[i] == pr[i-1]+2) ans.pb(pr[i-1]);

	while(scanf("%d", &n) != EOF) {
		printf("(%d, %d)\n", ans[n-1], ans[n-1]+2);
	} 
    return 0;
}
