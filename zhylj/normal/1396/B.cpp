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

int n; std::multiset <int> S;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		S.clear();
		rd(n);
		//printf("n = %d\n", n);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			S.insert(x);
			//printf("%d\n", x);
		}
		if(n == 1) {
			printf("T\n");
			continue;
		}
		while(S.size() > 2) {
			int bg = *S.begin(), ed = *S.rbegin();
			S.erase(S.find(bg)); S.erase(S.find(ed));
			if(bg - 1) S.insert(bg - 1);
			if(ed - 1) S.insert(ed - 1);
		}
		if(S.size() <= 1) printf("T\n");
		else printf(*S.begin() == *S.rbegin() ? "HL\n" : "T\n");
	} return 0;
}