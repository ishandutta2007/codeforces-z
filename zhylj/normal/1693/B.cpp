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

int n, p[N], dg[N]; ll L[N], R[N], tot[N];
//std::set <int> f[N];

void Merge(std::set <int> &A, std::set <int> &B) {
	if(A.size() < B.size()) std::swap(A, B);
	for(int b : B) A.insert(b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			//f[i].clear();
			tot[i] = dg[i] = 0;
		}
		int ans = 0;
		for(int i = 2; i <= n; ++i) rd(p[i]);
		for(int i = 1; i <= n; ++i) rd(L[i], R[i]);
		for(int i = n; i; --i) {
			if(tot[i] < L[i]) tot[i] = R[i], ++ans;
			if(tot[i] > R[i]) tot[i] = R[i];
			tot[p[i]] += tot[i];
		}
		printf("%d\n", ans);
	} return 0;
}