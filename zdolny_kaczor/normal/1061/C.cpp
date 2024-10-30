//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c h, n;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << '{';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << '}';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.n; ++s)
			u.f(*this << ", " + 2 * (s == u.h), *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
	muu & operator()() {ris;}
};
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int nax = 1e6 + 1, mod = 1e9 + 7;
int dp[nax];
vector <int> occ[nax];
vector <int> divs[nax];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < nax; ++i) {
		for (int k = i; k < nax; k += i)
			divs[k].push_back(i);
		if (i % 447 == 0)
			debug << imie(i);
	}
	debug;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		for (int d : divs[x])
			occ[d].push_back(i);
	}
	debug;
	long long ans = 0;
	vector <pair <int, int> > prev = {{-1, 1}};
	for (int d = 1; d <= n; ++d) {
		vector <pair <int, int> > curr;
		int sum_so_far = 0;
		int pos = 0;
		for (int k : occ[d]) {
			while (pos < (int)prev.size() && prev[pos].first < k) {
				sum_so_far += prev[pos].second;
				sum_so_far %= mod;
				pos++;
			}
			ans += sum_so_far;
			curr.emplace_back(k, sum_so_far);
		}
		debug << imie(d) imie(curr);
		swap(prev, curr);
	}
	debug;
	ans %= mod;
	assert(ans >= 0);
	printf("%lld\n", ans);
}