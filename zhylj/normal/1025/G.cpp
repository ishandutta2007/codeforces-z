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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod)
		if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, a[kN], cnt[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(~a[i]) ++cnt[a[i]];
		}
		ll bg = 0, ed = (-QPow(2, n - 1) + 1 + kMod) % kMod;
		for(int i = 1; i <= n; ++i) {
			bg = (bg - QPow(2, cnt[i]) + 1 + kMod) % kMod;
		}
		printf("%lld\n", (bg - ed + kMod) % kMod);
	} return 0;
}