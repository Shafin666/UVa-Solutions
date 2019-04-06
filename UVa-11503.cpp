#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
#define  read_input         freopen("in.txt","r", stdin)
#define  print_output       freopen("out.txt","w", stdout)
typedef long long ll;
typedef long double ld;
using namespace std;

int par[100005], sz[100005];

void init() {
    for(int i = 1;  i<= 100001; i++) par[i] = i;
    for(int i = 1;  i<= 100001; i++) sz[i] = 1;
}

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void join(int a, int b) {
    int x = find(a);
    int y = find(b);

    if(sz[y] > sz[x]) swap(x, y);
    if(x == y) return;

    sz[x] += sz[y];
    par[y] = x;
}

int main()
{   
    //read_input;
    //print_output;

    int tc, n;
    string s, t;
    map<string, int> M;

    cin >> tc;
    while(tc--) {
        init();
        M.clear();

        cin >> n;
        
        int c = 0;
        for(int i = 1; i <= n; i++) {
            cin >> s >> t;

            if(not M.count(s)) M[s] = ++c;
            if(not M.count(t)) M[t] = ++c;

            join(M[s], M[t]);
            cout << sz[find(M[s])] << endl;
        }
    }
    return 0;   
} 
