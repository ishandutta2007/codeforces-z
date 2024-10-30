//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
//#STAY AT HOME
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#define TIME (chrono::steady_clock::now().time_since_epoch().count())
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define xfm(a,b)a##b
#define xwb(a,b)xfm(a,b)
#define _ xwb(nvj,__LINE__)
#define __ xwb(kjy,__LINE__)
#define ___ xwb(cjm,__LINE__)
#define REP(i,n)for(urs(n)i=0;i<(n);++i)
#define UNTIL(t)while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define ALL(r)(r).begin(),(r).end()
#define RALL(r)(r).rbegin(),(r).rend()
#define FS(r)r.first,r.second
#define SF(r)r.second,r.first
#define M0(r) memset(r, 0, sizeof(r))
#define sim template<class c
#define ros return o
#define rans return ans
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=ctz(i##nvj))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=8*sizeof(m)-clz(i##nxd)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << (k)) - 1); m < ((t)1 << (n)); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
#define pwq(t,i) int clz(t x){return clz<int>(x)-i;}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using vll=vector<ll>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using spii=set<pii>;using mii=map<int,int>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class b,class cmp=less<c> >using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim, class cmp=less<c>>using ordered_set = ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#if defined(LOCAL) // || defined(LOCAL2)
#include </home/kjp/headers/debuglib.hpp>
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#define reg_it(...)
#define def_op(...) struct _{};
#define mask_set(...)
#if !defined(LOCAL) && !defined(LOCAL2)
#define exit my_exit
void my_exit(int x) {fflush(stdout);_Exit(x);}
#endif
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
#define pow do not use cmath pow unless you know what you are doing
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;ros;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=(ll)(a*(ld)b/m);ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
#pragma GCC diagnostic pop
#if ((ULONG_MAX) != (UINT_MAX))
namespace std {template <> struct is_signed<__int128> : public true_type {};}
#endif
sim, class d> typename common_type<c,d>::type floor_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using floor_div with different signedness");if (b < 0) b = -b, a = -a;return a / b - (a % b < 0);}
sim, class d> typename common_type<c,d>::type ceil_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using ceil_div with different signedness");if (b < 0) b = -b, a = -a;return a / b + (a % b > 0);}
sim> struct REV {using value_type=typename c::value_type;c &x;using it=typename c::reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> struct CREV {using value_type=typename c::value_type;const c&x;using it=typename c::const_reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> REV<c> reversed(c&x) {return REV<c>{x};}sim> CREV<c> reversed(const c&x) {return CREV<c>{x};}
#define done(r...) exit(0 * printf(r))
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << setprecision(6) << fixed << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
//#STAY AT HOME
const int nax = 1 << 19;
vi graf[nax];
int dist[2][nax];
pii furthest(int x, int y = -1) {
	pii ans = {0, x};
	for (int v : graf[x]) if (v != y) {
		pii ret = furthest(v, x);
		maxi(ans, pii(ret.first + 1, ret.second));
	}
	rans;
}
void calc_dist(int x, int ans[], int y = -1, int d = 0) {
	ans[x] = d;
	for (int v : graf[x]) if (v != y) calc_dist(v, ans, x, d + 1);
}
int dep[nax], left[nax], right[nax];
void dfs(int x, int y = -1, int d = 0) {
	static int timer = 0;
	left[x] = timer++;
	dep[x] = d;
	for (int v : graf[x]) if (v != y) dfs(v, x, d + 1);
	right[x] = timer;
	debug(arr(left, x), arr(right, x));
}
struct value {
	int top[2][2];
};
value tree[2 * nax];
value init(int d1, int d2) {
	return {d1, d2, 0, 0};
}
value merge(value a, value b) {
	value ret;
	REP(i, 2) REP(j, 2) ret.top[i][j] = max(a.top[i][j], b.top[i][j]);
	return ret;
}
value flip(value a) {
	REP(i, 2) swap(a.top[i][0], a.top[i][1]);
	return a;
}
value beg[nax];
bool flipped[2 * nax];
bool read_col(int x) {
	x = left[x] + nax;
	bool ans = 0;
	while (x) {
		ans ^= flipped[x];
		x /= 2;
	}
	rans;
}
void flip_seg(int l, int r, int wh = 1, int lb = 0, int rb = nax) {
	if (l >= rb || r <= lb) return;
	if (l <= lb && r >= rb) {
		debug(imie(lb), imie(rb));
		flipped[wh] ^= 1;
		tree[wh] = flip(tree[wh]);
		return;
	}
	int sb = (lb + rb) / 2;
	flip_seg(l, r, wh * 2, lb, sb);
	flip_seg(l, r, wh * 2 + 1, sb, rb);
	tree[wh] = merge(tree[wh * 2], tree[wh * 2 + 1]);
	if (flipped[wh]) tree[wh] = flip(tree[wh]);
}
void flip_tree(int x) {
	flip_seg(left[x], right[x]);
}
vpii edge;
void flip_edge(int num) {
	auto [a, b] = edge[num];
	debug(imie(a), imie(b));
	flip_tree(dep[a] > dep[b] ? a : b);
}
void solve() {
	int n;
	scanf("%d", &n);
	edge.resize(n - 1);
	vi to_flip;
	REP(i, n - 1) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		graf[a].push_back(b);
		graf[b].push_back(a);
		edge[i] = {a, b};
		if (t)
			to_flip.push_back(i);
	}
	dfs(1);
	int e0 = furthest(1).second, e1 = furthest(e0).second;
	calc_dist(e0, dist[0]);
	calc_dist(e1, dist[1]);
	for (int i = 1; i <= n; ++i) beg[left[i]] = init(dist[0][i], dist[1][i]);
	for (int i = 0; i < nax; ++i) tree[i + nax] = beg[i];
	for (int i = nax - 1; i ; --i) tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
	debug(dump(tree[1].top, 0, 2, 0, 2));
	for (int c : to_flip) flip_edge(c);
	int q;
	scanf("%d", &q);
	debug(imie(q));
	REP(_, q) {
		int num;
		scanf("%d", &num);
		flip_edge(num - 1);
		int ans = 0;
		debug(dump(tree[1].top, 0, 2, 0, 2));
		REP(i, 2) {
			int e = i ? e1 : e0;
			int my_col = read_col(e);
			int far = tree[1].top[i][my_col];
			debug(imie(e), imie(i), imie(my_col), imie(far));
			maxi(ans, far);
		}
		printf("%d\n", ans);
	}
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME