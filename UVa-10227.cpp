#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
typedef long long ll;
typedef long double ld;
using namespace std;

std::vector<int> primes;
set<int> adj[105];
bool mark[1007];

void sieve(int n) {
	int i, j, limit = sqrt(n*1.0)+2;

	primes.pb(2);
	mark[1] = 1;

	for(i = 4; i <= n; i += 2) mark[i] = 1;
	for(i = 3; i <= n; i += 2) {
		if(!mark[i]) {
			primes.pb(i);

			if(i <= limit)
				for(j = i*i; j <= n; j += i*2) mark[j] = 1;
		}
	}
}
int to_int(string str) {
	if(str.length() == 1) return str[0]-48;
	else return (str[0]-48)*10 + (str[1]-48);
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	sieve(1005);

	int tc, n, m;
	int i, c = 0;
	int x, y; 
	ll M =  1111111111111111111;
	string str, w;

	cin >> tc;
	while(tc--) {
		cin >> n >> m; getchar();
		set<ll> s;

		while(getline(cin, str) && str != "") {
			stringstream s(str);
			int i = 0, a[3];

			while(s >> w)
				a[i++] = to_int(w);
			adj[a[0]].insert(a[1]);
		}

		for(i = 1; i <= n; i++) {
			ll k = 1; for(auto it : adj[i]) k = (primes[it]*k) % M;
			s.insert(k); adj[i].clear();
		}
		
		if(c++) cout << endl;
		cout << s.size() << endl;
		s.clear();
	}

    return 0;
}
