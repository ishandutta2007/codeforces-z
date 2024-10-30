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
const int nax = 3e5 + 44;
vi graf[nax];
map <pii, int> wei;
set <pii> bridges;
bool spe[nax];
int c[nax];
int u[nax];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
void onion(int a, int b) {
	u[find(a)] = find(b);
}
void reset() {
	iota(u, u + nax, 0);
}
void dfs1(int x, int y = -1) {
	static int timer = 1;
	static int pre[nax], low[nax];
	pre[x] = low[x] = timer++;
	for (int v : graf[x]) if (v != y) {
		if (pre[v] == 0) {
			dfs1(v, x);
			mini(low[x], low[v]);
		}
		else
			mini(low[x], pre[v]);
	}
	for (int v : graf[x]) if (v != y && low[v] > pre[x]) {
		bridges.emplace(v, x);
	}
	debug(arr(pre, x), arr(low, x), arr(graf, x));
}
int w_[nax], a_[nax], b_[nax];
ll csum[nax];
vi tree[nax];
bool rem[nax];
ll ans[nax];
bool dfs2(int x, int y = -1) {
	bool has = spe[x];
	for (int v : tree[x]) if (v != y) {
		if (dfs2(v, x))
			has = true;
		else {
			onion(x, v);
			csum[x] += csum[v];
		}
	}
	rem[x] = !has;
	return has;
}
int get_wei(int a, int b) {
	if (a > b) swap(a, b);
	auto it = wei.find(pii(a, b));
	assert(it != wei.end());
	return it->second;
}
ll down[nax], up[nax];
void dfs3(int x, int y = -1) {
	down[x] = csum[x];
	for (int v : tree[x]) if (v != y && !rem[v]) {
		dfs3(v, x);
		down[x] += max(0ll, down[v] - get_wei(v, x));
	}
}
void dfs4(int x, int y = -1) {
	ll su = 0;
	if (y != -1) su += max(0ll, up[x] - get_wei(x, y));
	for (int v : tree[x]) if (v != y && !rem[v]) {
		su += max(0ll, down[v] - get_wei(v, x));
	}
	for (int v : tree[x]) if (v != y && !rem[v]) {
		up[v] = su - max(0ll, down[v] - get_wei(v, x)) + csum[x];
		ans[find(v)] = max(0ll, up[v] - get_wei(v, x)) + down[v];
	}
	for (int v : tree[x]) if (v != y && !rem[v]) dfs4(v, x);
}
void solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	REP(_, k) {
		int x;
		scanf("%d", &x);
		spe[x] = true;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	REP(i, m) scanf("%d", w_ + i);
	REP(i, m) scanf("%d%d", a_ + i, b_ + i);
	REP(i, m) {
		int a = a_[i], b = b_[i], w = w_[i];
		if (a > b) swap(a, b);
		wei[pii(a, b)] = w;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1);
	debug(imie(bridges));
	reset();
	for (int v = 1; v <= n; ++v) for (int w : graf[v]) if (!bridges.count(pii(v, w)) && !bridges.count(pii(w, v)))
		onion(v, w);
	for (int v = 1; v <= n; ++v) csum[find(v)] += c[v];
	for (auto [a, b] : bridges) {
		int w = get_wei(a, b);
		a = find(a);
		b = find(b);
		wei[pii(a, b)] = wei[pii(b, a)] = w;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int my_root = -1;
	for (int v = 1; v <= n; ++v) if (spe[v]) {
		my_root = find(v);
		spe[find(v)] = true;
	}
	assert(my_root != -1);
	dfs2(my_root);
	debug(draw_tree(my_root, tree, [](int x){stringstream o; o << "{" << x << ": " << boolalpha << rem[x] << ", " << csum[x] << "}"; ros.str();}));
	dfs3(my_root);
	dfs4(my_root);
	ans[find(my_root)] = down[my_root];
	for (int i = 1; i <= n; ++i) printf("%lld ", ans[find(i)]);
	printf("\n");
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME