#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 1e5 + 44;
VPII queries[MN];
int a[MN];
int dp[MN * 3];
int ans[MN];
int main() {
	int n, q;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int p, k;
		scanf("%d%d", &p, &k);
		queries[k].PB(MP(p, i));
	}
	for (int k = 1; k <= n; ++k) {
		if (k < 500) {
			for (int i = n; i > 0; --i) {
				dp[i] = 1 + dp[i + k + a[i]];
			}
			for (PII x : queries[k])
				ans[x.second] = dp[x.first];
		}
		else {
			for (PII x : queries[k]) {
				int p = x.first;
				while (p <= n) {
					ans[x.second]++;
					p += a[p] + k;
				}
			}
		}
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
}