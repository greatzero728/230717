#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[1212];
vector<string> vec;

bool same(string s, int st, int n) {
	for(int i = n; i--; ) if(s[st + i] != ::s[i]) {
		return 0;
	}
	return 1;
}

bool is_in(int n) {
	for(string s: vec) if(s.size() >= n) {
		for(int i = n - 1; i < s.size(); i++) if(same(s, i - n + 1, n)) {
			return 1;
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("nenokku_easy.in", "r", stdin);
	freopen("nenokku_easy.out", "w", stdout);
#endif
	
	char c;
	while(~scanf(" %c", &c)) {
		scanf("%s", s);
		for(int i = 0; s[i]; i++) if(isupper(s[i])) {
			s[i] = s[i] - 'A' + 'a';
		}
		if(c == 'A') {
			if(vec.empty()) vec.push_back("");
			vec.back() += s;
		}
		else if(is_in(strlen(s))) puts("YES");
		else puts("NO");
	}
	return 0;
}
