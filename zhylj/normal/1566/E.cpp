#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
    int si = 1; char c = getchar(); x = 0;
    while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
    while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
    x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, typ[N];
std::vector <int> E[N];
void Dfs(int u, int p) {
	int ch_cnt = 0;
	typ[u] = 1;
	for(int v : E[u]) if(v != p) {
		Dfs(v, u);
		if(typ[v] == 1)
			typ[u] = 0;
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
		for(int i = 1; i <= n; ++i) E[i].clear();
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		Dfs(1, 0);
		int ans = 0;
		for(int i = 2; i <= n; ++i) {
			if(!typ[i]) --ans;
			else ++ans;
		}
		if(typ[1]) ++ans;
		printf("%d\n", ans);
    } return 0;
}