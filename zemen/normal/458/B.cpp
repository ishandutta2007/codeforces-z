#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "b"
#define LOCAL_INPUT NAME ".in"
//~ #define LOCAL_OUTPUT NAME ".out"
//~ #define INPUT NAME ".in"
//~ #define OUTPUT NAME ".out"

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
		clock_t start = clock();
		#ifdef LOCAL_INPUT
			assert(freopen(LOCAL_INPUT, "r", stdin));
		#endif
		#ifdef LOCAL_OUTPUT
			assert(freopen(LOCAL_OUTPUT, "w", stdout));
		#endif
	#else
		#ifdef INPUT
			assert(freopen(INPUT, "r", stdin));
		#endif
		#ifdef OUTPUT
			assert(freopen(OUTPUT, "w", stdout));
		#endif
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef _GEANY
		fprintf(stderr, "Time: %.3fs\n", double(clock() - start) / CLOCKS_PER_SEC);
	#endif
}

int a[100001];
int b[100001];

void solve() {
	int n, m;
	cin >> n >> m;
	ll A = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		A += a[i];
	}
	ll B = 0;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		B += b[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	sort(b, b + m);
	reverse(b, b + m);
	ll res = INFL;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (B * (i + 1) > res)
			break;
		res = min(res, B * (i + 1) + (A - sum));
	}
	sum = 0;
	for (int i = 0; i < m; ++i) {
		sum += b[i];
		if (A * (i + 1) > res)
			break;
		res = min(res, A * (i + 1) + (B - sum));
	}
	cout << res << '\n';
}