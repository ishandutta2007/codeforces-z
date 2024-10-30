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

int n, k; ll a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			a[i] = a[i - 1] + a[i];
		}
		std::sort(a + 1, a + n + 1);
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			int len = std::min(i + k - 1, n) - (i - 1);
			ans = std::max(ans, 1LL * k * len - 1LL * len * (len + 1) / 2 + a[std::min(i + k - 1, n)] - a[i - 1]);
		}
		printf("%lld\n", ans);
	} return 0;
}