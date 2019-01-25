#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
typedef long long ll;
typedef long double ld;
using namespace std;

ll egcd(ll a, ll b, ll &x, ll &y) {
	if(!a) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll g = egcd(b%a, a, x1, y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return g;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	ll n1, n2;
	ll c1, c2;
	ll s;

	while(cin >> s && s) {
		cin >> c1 >> n1;
		cin >> c2 >> n2;

		ll x, y, g;
		g = egcd(n1, n2, x, y);

		if(s % g != 0 || (n1 > s) || (n2 > s)) {cout << "failed" << endl; continue;}

		x *= s/g; y *= s/g;

		ll xmini_ceil = (abs(x)+(n2/g)-1)/(n2/g);
		ll xmini_floor = abs(x)/(n2/g);

		ll xmini_x, xmini_y;
		if(x < 0) {
			xmini_x = x + xmini_ceil*(n2/g);
			xmini_y = y - xmini_ceil*(n1/g);
		}
		else {
			xmini_x = x - xmini_floor*(n2/g);
			xmini_y = y + xmini_floor*(n1/g);
		}
		ll xmini_cost = xmini_x*c1 + xmini_y*c2;
		
		ll ymini_ceil = (abs(y)+(n1/g)-1)/(n1/g);
		ll ymini_floor = abs(y)/(n1/g);

		ll ymini_x, ymini_y;
		if(y < 0) {
			ymini_x = x - ymini_ceil*(n2/g);
			ymini_y = y + ymini_ceil*(n1/g);
		}
		else {
			ymini_x = x + ymini_floor*(n2/g);
			ymini_y = y - ymini_floor*(n1/g);
		}
		ll ymini_cost = ymini_x*c1 + ymini_y*c2;

		if(xmini_cost < ymini_cost) {
			if(xmini_x < 0 || xmini_y < 0) cout << "failed" << endl;
			else cout << xmini_x << " " << xmini_y << endl;
		}
		else {
			if(ymini_x >= 0 && ymini_y >= 0) cout << ymini_x << " " << ymini_y << endl;
			else cout << "failed" << endl;
		}
	}

    return 0;
}
