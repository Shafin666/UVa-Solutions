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

	int n, a, b;
	stack<int> s;
	queue<int> q;
	priority_queue<int> pq;

	while(scanf("%d", &n) != EOF) {
		int stak = 0, queu = 0, priority = 0;
		int queries = 0, f = 1;
		
		while(n--) {
			scanf("%d%d", &a, &b);

			if(a-1) {
				queries++;
				if(s.empty() || pq.empty() || q.empty()) {f = 0; continue;}
				int stk = s.top(), que = q.front(), pque = pq.top();

				if(b == stk && b == que && b == pque) stak++, queu++, priority++;
				else if(b == stk && b == que)  stak++, queu++;
				else if(b == que && b == pque) queu++, priority++;
				else if(b == stk && b == pque) stak++, priority++;
				else if(b == stk) stak++;
				else if(b == que) queu++;
				else if(b == pque) priority++;
				else f = 0;

				s.pop(); q.pop(); pq.pop();
			} else {
				s.push(b);
				q.push(b);
				pq.push(b);
			}
		}
		if(!f) printf("impossible\n");
		else {
			if(stak == queries && queu == queries && priority == queries) printf("not sure\n");
			else if((stak == queries && queu == queries) || (stak == queries && priority == queries) || (queu == queries && priority == queries))
				printf("not sure\n");
			else if(stak == queries) printf("stack\n");
			else if(queu == queries) printf("queue\n");
			else if(priority == queries)printf("priority queue\n");
			else printf("impossible\n");
		}
		while(!s.empty()) s.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
	}
    return 0;
}
