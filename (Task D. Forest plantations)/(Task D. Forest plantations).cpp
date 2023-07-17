#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define pc _putchar_nolock
static char fjf[1010], so[44];
void pt(int x) {
	int n = 0; while(so[n++] = x % 10, x /= 10);
	while(n--) pc(so[n] + 48);
}
char gc() {
	static char *L = fjf, *R = L;
	if(L == R) {
		int n = fread(fjf, 1, 1010, stdin);
		if(!n) return -1; L = fjf, R = L + n;
	}
	return *L++;
}
bool gn(int &x) {
	char c; while(c = gc(), (c < 48 || 57 < c) && ~c);
	for(x = c - 48; c = gc(), 48 <= c && c <= 57; x = 10 * x + c - 48);
	return 1;
}


int n, m;

const int NN = 121;

int a[NN][NN];
bool flag[NN][NN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("forest.in", "r", stdin);
	freopen("forest.out", "w", stdout);
#endif
	
	gn(n), gn(m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) gn(a[i][j]);
	}
	
	static int i, j, k, x, y;
	for(int step = 0; ; step++) {
		bool can_grow = 0;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				flag[i][j] = 0;
				for(k = 4; k--; ) {
					if(a[i + dx[k]][j + dy[k]] == a[i][j] + 1) {
						flag[i][j] = 1; break;
					}
				}
				if(flag[i][j]) can_grow = 1;
			}
		}
		if(!can_grow) {
			pt(step), pc(10);
			for(i = 1; i <= n; i++) {
				for(j = 1; j <= m; j++) pt(a[i][j]), pc(' ');
				pc(10);
			}
			return 0;
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				if(flag[i][j]) a[i][j]++;
			}
		}
	}
	return 0;
}
