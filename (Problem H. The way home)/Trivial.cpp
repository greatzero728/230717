#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

bool flag[202020];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("test.txt", "w", stdout);
#else
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	stack<int> s;
	while(n--) {
		int x; scanf("%d", &x);
		if(x > 0) s.push(x), flag[x] = 0;
		else if(x < 0) flag[-x] = 1;
		else if(!s.empty()) flag[s.top()] = 0, s.pop();
		while(!s.empty() && flag[s.top()]) s.pop();
		if(s.empty()) puts("0");
		else printf("%d\n", s.top());
	}
	return 0;
}