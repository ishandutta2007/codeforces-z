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
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using spii=set<pii>;using mii=map<int,int>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class b,class cmp=less<c> >using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim, class cmp=less<c>>using ordered_set = ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
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
#define vsv sim,class d,class e
#define nop(o,c,r,l...)>auto operator o(const c&a,const r&b)->decltype(make_pair(l)){return{l};}
#define pcg(o) vsv,class f nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second)vsv,class=typename enable_if<!is_base_of<ios_base,c>::value>::type nop(o,c,pair<d u e>,a o b.first,a o b.second)vsv nop(o,pair<c u d>,e,a.first o b,a.second o b)
#define clp(o) pcg(o)vsv>void operator o##=(pair<c,d>&a,const e&b){a.first o##=b;a.second o##=b;}vsv,class f>void operator o##=(pair<c,d>&a,const pair<e,f>&b){a.first o##=b.first;a.second o##=b.second;}
#define syd(o) sim,class d>auto operator o(pair<c, d> e)->decltype(make_pair(o e.first,o e.second)){return{o e.first,o e.second};}
#define u ,
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)
#undef u
const int nax = 5010;
vi graf[nax];
int col[nax];
pii dfs(int x, int c) {
	if (col[x] != -1) {
		if (col[x] == c) return {0, 0};
		done("NO\n");
	}
	pii ans = {c == 0, c == 1};
	col[x] = c;
	for (int v : graf[x]) ans += dfs(v, c ^ 1);
	rans;
}
bool can[nax][nax];
int u[nax];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
void onion(int a, int b) {
	u[find(a)] = find(b);
}
int n, m;
void flip(int v) {
	debug(imie(v));
	v = find(v);
	for (int i = 1; i <= n; ++i) if (find(i) == v) col[i] ^= 1;
}
int main() {
	scanf("%d%d", &n, &m);
	int n1, n2, n3;
	scanf("%d%d%d", &n1, &n2, &n3);
	iota(u, u + nax, 0);
	REP(_, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		graf[x].push_back(y);
		graf[y].push_back(x);
		onion(x, y);
	}
	memset(col, -1, sizeof(col));
	vector <pair <pii, int> > coms;
	for (int i = 1; i <= n; ++i) if (col[i] == -1) coms.emplace_back(dfs(i, 0), i);
	debug(imie(coms));
	debug(range(col, 1, n + 1));
	can[0][0] = 1;
	int l = coms.size();
	for (int i = 0; i < l; ++i) {
		auto [a, b] = coms[i].first;
		for (int x : vi{a, b})
			for (int j = 0; j + x < nax; ++j)
				if (can[i][j])
					can[i + 1][j + x] = 1;
	}
	if (!can[l][n2]) done("NO\n");
	printf("YES\n");
	int su = n2;
	for (int i = l; i; --i) {
		auto [a, b] = coms[i - 1].first;
		int nu = coms[i - 1].second;
		int take = -1;
		if (su >= a && can[i - 1][su - a]) take = a;
		else if (su >= b && can[i - 1][su - b]) take = b;
		assert(take != -1);
		if (take == a) flip(nu);
		su -= take;
	}
	int ones = 0;
	for (int i = 1; i <= n; ++i) {
		if (!col[i]) {
			if (ones < n1) {
				putchar('1');
				ones++;
			}
			else
				putchar('3');
		}
		else
			putchar('2');
	}
	printf("\n");
	exit(0);
}
//#STAY AT HOME