#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

using pII = pair<INT, INT>;

vector<pII> ans;

void solve(INT n) {
	if(n <= 2) return;
	INT x = sqrt(n), y;
	while(x * x < n) x++;
	solve(x), solve(y = x * x - n);
	ans.push_back({x, y});
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	INT n; cin>>n;
	solve(n);
	
	unordered_set<INT> s;
	for(pii p : ans) {
		INT x = p.x, y = p.y;
		INT w = x * x - y;
		if(s.find(w) == s.end()) {
			cout<<x<<' '<<y<<endl;
			s.insert(w);
		}
	}
	return 0;
}
