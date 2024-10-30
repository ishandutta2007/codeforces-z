#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;

int n, dg[N], f[N];
std::vector <int> E[N];
void Dfs(int u, int p) {
	for(int v : E[u]) if(v != p) {
		f[v] = f[u] ^ 1;
		Dfs(v, u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) dg[i] = f[i] = 0, E[i].clear();
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
			++dg[u]; ++dg[v];
		}
		Dfs(1, 0);
		for(int i = 1; i <= n; ++i) {
			printf("%d ", dg[i] * (f[i] ? 1 : -1));
		}
		printf("\n");
	} return 0;
}