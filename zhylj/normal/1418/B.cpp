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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN], b[kN], cnt = 0;
bool flag[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		cnt = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			flag[i] = x;
			if(!flag[i]) b[++cnt] = a[i];
		}
		std::sort(b + 1, b + cnt + 1);
		std::reverse(b + 1, b + cnt + 1);
		for(int i = 1, j = 1; i <= cnt; ++i) {
			while(flag[j]) ++j;
			a[j++] = b[i];
		}
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
		printf("\n");
	} return 0;
}