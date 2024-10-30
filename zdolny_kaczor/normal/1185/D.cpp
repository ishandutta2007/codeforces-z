//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
# include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); ++i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); --i)
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
#define ALL(r) (r).begin(), (r).end()
#define FS(r) r.first, r.second
#define MAKE(b, e) <urs(*(b))>(b, e)
#define sim template <class c
#define ros return o
#define rans return ans
#define forbits(i, m) if (m) for (urs(m) i = ctz(m), quq = m; quq; quq ^= ((decltype(m))1 << i), i = ctz(quq)) 
#define fordbits(i, m) if (m) for (urs(m) i = 8 * sizeof(m) - clz(m) - 1, quq = m; quq; quq ^= ((decltype(m))1 << i), i = 8 * sizeof(m) - clz(quq) - 1)
#define hur(f, g) int f(unt a) {return g(a);} int f(int a) {return g(a);} \
int f(ll a) {return g##ll(a);} int f(ull a) {return g##ll(a);}
using ll = long long; using ld = long double; using ull = unsigned long long;using pii = pair <int, int>;
using vpii = vector <pii>; using unt = unsigned int;sim> using min_queue = priority_queue<c, vector<c>, greater<c>>;
template <typename T>using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)
sim,class N>bool mini(c&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,N h){if(o<h)ros=h,1;return 0;}
#ifdef LOCAL
ostream & operator<<(ostream &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
ostream & operator<<(ostream &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
#define oor >ostream &operator<<(ostream &o,
#define urs(r) typename pta<typename remove_reference<decltype(r)>::type>::t
#define bnt ;}sim> struct
sim,class N oor pair<c,N>u){ros<<"<"<<u.first<<", "<<u.second<<">" bnt pta{using t=c;}; sim,int N>struct pta<c[N]>{using t=c*;};
sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){
int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<e;ros<<"}";} void dor(){cerr<<dec<<"\033[0m"<<endl;}
sim,class...N>void dor(c x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);}
#define debug(c...)cerr<<"\033[1;"<<30+__LINE__%8<<"m"<<__FUNCTION__<<"#"<<__LINE__<<": \033["<<30+(int)(__LINE__*3.125)%8<<"m",::dor(c)
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
sim>string bte(c u){stringstream o;o<<boolalpha<<u;ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);
sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}
#define g(o) template<zub(o, v o u, N) "(" + bte(*this) + ") " #o " (" + bte(u) + ")", m);}
template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};
sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}
sim>c yyo(nep<c> o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
#define ccy(r...) sim> class enable_if<r is_arithmetic<c>::value,string>::type ema(c u){
ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}
#undef g
#define g(o) sim, zub(o, yyo(p) o u.v, c p, nep<N>) "(" + bte(p) + ") " #o " (" + bte(u) + ")", uhn(p) + u.m);}
sim>string bte(nep<c>o){ros.d+" = "+(o.m?ema(o.v):bte(o.v));}
sim oor nep<c>m){ros<<bte(rcu sim> nep<c> ngy(nep<c> o,string d="",int m=0){ros;}
#undef g
#define imie(a...) ngy(a, #a)
#define imask(a...) ngy(a, #a, 1)
#define range_v(u, g, c) ngy(list<urs(u[0])>(&u[yyo(g)], &u[yyo(c)] + 1), #u "[" + bte(g) + "..." + bte(c) + "]")
#define range(i, j) ngy(list<urs(*i)>(i, j), "[" #i "..." #j ")")
#define arr(a, i) imie(a)[imie(i)]
#define arr2(a, i, j) imie(a)[imie(i)][imie(j)]
#define arr3(a, i, j, k) imie(a)[imie(i)][imie(j)][imie(k)]
#define arr4(a, i, j, k, q) imie(a)[imie(i)][imie(j)][imie(k)][imie(q)]
#define ckx(o) template<zub(o, o yyo(u), nep<N>) #o "(" + bte(u) + ")", u.m);}
ckx(+)ckx(-)ckx(!)ckx(~)
#else
#define debug(...)
#endif
#define vsv sim, class d, class e
#define nop(o,c,r,l...) auto operator o(c a, r b)-> decltype(make_pair(l)) {return {l};}
#define pcg(o) vsv, class f> nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second) \
vsv,class = typename enable_if<!is_base_of<ios_base, c>::value>::type> nop(o, c, pair<d u e>, a o b.first, a o b.second) \
vsv> nop(o, pair<c u d>, e, a.first o b, a.second o b)
#define clp(o) pcg(o) \
vsv> void operator o##= (pair <c,d> & a, e b) {a.first o##= b; a.second o##= b;} \
vsv, class f> void operator o##= (pair <c,d> & a, pair <e,f> b) {a.first o##= b.first; a.second o##= b.second;}
#define syd(o) sim, class d> auto operator o(pair<c, d> e) -> decltype(make_pair(o e.first, o e.second)) {return {o e.first, o e.second};}
#define u ,
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)
#undef u
ull mix(ull x){x += 0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
sim,class n>using gyv=c;namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&x)const{
return mix(hash<c>()(x.first))^hash<n>()(x.second);}};sim>struct hash<gyv<c, typename c::value_type>>
{size_t operator()(const c&x)const{size_t ans = x.size();for (auto &e : x) ans = mix(ans ^ hash<typename c::value_type>()(e));rans;}};};
#ifndef LOCAL
sim, class m> using _un0rDer3d_M4P = cc_hash_table<c, m, hash<c>>;
#define unordered_map _un0rDer3d_M4P
#endif
void fre(string c) {
#if !defined(LOCAL) && !defined(LOCAL2)
	freopen((c+".in").c_str(), "r", stdin);
	freopen((c+".out").c_str(), "w", stdout);
#endif
}
const int nax = 2e5 + 44;
pii a[nax];
int main() {
	int n;
	scanf("%d", &n);
	ll sum = 0;
	REP(i, n) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
		sum += a[i].first;
	}
	sort(a, a + n);
	REP(i, n) {
		if (i && a[i].first == a[i - 1].first) continue;
		int low = a[0].first, high = a[n - 1].first;
		if (i == 0) low = a[1].first;
		if (i == n - 1) high = a[n - 2].first;
		ll real_sum = 2 * (sum - a[i].first);
		ll exp_sum = (low + high) * (n - 1ll);
		debug(imie(low), imie(high), imie(real_sum), imie(exp_sum));
		if (real_sum == exp_sum) {
			debug("check ", arr(a, i));
			vector <int> seq;
			REP(j, n) if (i != j) seq.push_back(a[j].first);
			bool good = true;
			REP(j, n - 3) {
				if (seq[j + 2] + seq[j] - 2 * seq[j + 1]) {
					good = false;
					break;
				}
			}
			if (good) return 0 * printf("%d\n", a[i].second);
		}
	}
	printf("-1\n");
}