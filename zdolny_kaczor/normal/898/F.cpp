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
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
#define debug if(0) cout
#endif
template <typename T, typename C>
ostream & operator<<(ostream &os, pair<T, C> x) {
	return os << "<" << x.f << ", " << x.s << ">";
}
template <typename T>
auto operator<<(ostream&os, T x) -> typename enable_if<is_same<decltype(x.begin()), decltype(x.end())>::value && !is_same<T, string>::value, ostream &>::type {
	os << "{";
	int cou = 0;
	for (auto c : x) {
		if (cou++)
			os << ", ";
		os << c;
	}
	return os << "}";
}
#define cr << "][" << 
#define rr << "] = " << 
#define cc << "[" <<
#define ao << ' ' 
#define name(a) #a << " = " << (a) ao
#define arr(a, i) #a cc #i rr #a cc i rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q] ao
template <typename T>
string strmask(T r) {
	string ans;
	REP(i, 8 * (int)sizeof(T)) {
		ans += '0' + !!(((T)1 << i) & r);
		if (i % 5 == 4)
			ans += '.';
	}
	return ans;
}
#if 0 
ostream & operator<< (ostream & os, __int128_t x) {
	if (x < 0) {
		os << '-';
		x = -x;
	}
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
ostream & operator<< (ostream & os, __uint128_t x) {
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
#endif
#define nmask(a) #a << " = " << strmask(a) ao
const int MN = 1e6 + 44;
char in[MN];
const int mod = 1998197207;
LL pows[MN];
LL sums[MN];
int n;
LL range(int i, int l) {
	return ((sums[i + l] - sums[i] * pows[l]) % mod + mod) % mod;
}
void check(int sum, int s1, int s2) {
	debug << name(sum) << name(s1) << name(s2) << endl;
	assert(sum + s1 + s2 == n);
	if (s1 == 0 || s2 == 0 || (s1 != 1 && in[0] == '0') || (s2 != 1 && in[s1] == '0'))
		return;
	if ((range(0, s1) + range(s1, s2) - range(s1 + s2, sum)) % mod == 0) {
		REP(i, n) {
			if (i == s1)
				putchar('+');
			if (i == s1 + s2)
				putchar('=');
			putchar(in[i]);
		}
		exit(0);
	}
}
int main() {
	pows[0] = 1;
	FOR(i, 1, MN - 1)
		pows[i] = pows[i - 1] * 10 % mod;
	scanf("%s", in);
	n = strlen(in);
	sums[0] = 0;
	FOR(i, 1, n)
		sums[i] = (sums[i - 1] * 10 + in[i - 1] - '0') % mod;
	FOR(len, (n + 2) / 3, n / 2) {
		check(len, len, n - len * 2);
		check(len, len - 1, n - len * 2 + 1);
		check(len, n - len * 2, len);
		check(len, n - len * 2 + 1, len - 1);
	}
}