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
const int kN = 1e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		int x, s = 0; bool flag = true, flag2 = false;
		rd(n, x);
		for(int i = 1; i <= n; ++i) rd(a[i]), s += a[i] - x;
		for(int i = 1; i <= n; ++i) {
			if(a[i] != x) flag = false;
			if(a[i] == x) flag2 = true;
		}
		if(flag) printf("0\n");
		else if((!s) || flag2) printf("1\n");
		else printf("2\n");
	} return 0;
}