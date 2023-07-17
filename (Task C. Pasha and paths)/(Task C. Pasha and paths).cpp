#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

using DO = long double;

const int NN = 101010, MM = NN << 1;

int head[NN], nxt[MM], to[MM], wei[MM], E;
bool flag[MM], vst[NN];

void add(int u, int v, int w, bool f) {
	wei[E] = w, flag[E] = f;
	to[E] = v, nxt[E] = head[u], head[u] = E++;
	return;
}

int sz;

void dfs_sz(int u, int f = 0) {
	vst[u] = 1, sz++;
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		if(v != f && !flag[e]) dfs_sz(v, u);
	}
	return;
}

INT s;

int dfs_calc_0(int u, int f = 0) {
	int cnt = 1;
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		if(v != f && !flag[e]) {
			int x = dfs_calc_0(v, u);
			s += (INT)wei[e] * x * (sz - x);
			cnt += x;
		}
	}
	return cnt;
}

int dfs_calc(int u, int f = 0) {
	int cnt = 1;
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		if(v != f) {
			int x = dfs_calc(v, u);
			s += (INT)wei[e] * x * (sz - x);
			cnt += x;
		}
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) head[i] = -1;
	
	for(int i = 1; i < n; i++) {
		int u, v, w, f; scanf("%d %d %d %d", &u, &v, &w, &f);
		add(u, v, w, f), add(v, u, w, f);
	}
	
	sz = n, dfs_calc(1);
	INT ans = s, cnt = (INT)n * (n - 1) >> 1;
	
	for(int i = 1; i <= n; i++) if(!vst[i]) {
		sz = 0, dfs_sz(i), cnt -= (INT)sz * (sz - 1) >> 1;
		s = 0, dfs_calc_0(i), ans -= s;
	}
	
	printf("%.9lf\n", (double)((DO)ans / cnt));
	return 0;
}