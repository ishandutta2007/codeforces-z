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
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define FS(r)r.first,r.second
#define ALL(r)(r).begin(),(r).end()
#define M0(r) memset(r,0,sizeof(r))
#define sim template<class c
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=i##nvj?ctz(i##nvj):0)
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=i##nxd?8*sizeof(m)-clz(i##nxd)-1:0)
#define ksets(t, m, k, n)for(t m=(((t)1<<(k))-1);m<((t)1<<(n));m=nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g)sim>int f(c a){if(sizeof(c)==8)return g##ll(a);return g(a);}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using vll=vector<ll>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<>>;sim,class b,class cmp=less<c>>using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim,class cmp=less<c>>using ordered_set=ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount)hur(ctz,__builtin_ctz)hur(clz,__builtin_clz)sim,class N>bool mini(c&o,const N&h){if(o>h)return o=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)return o=h,1;return 0;}
#ifdef LOCAL
#include </home/konrad/cp/headers/debuglib.hpp>
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
#define exit my_exit
void __resources();
void my_exit(int x) {fflush(stdout);
#ifdef LOCAL2
__resources();
#endif
_Exit(x);}
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
#define pow don't'
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;return o^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf=1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;return o;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
//#STAY AT HOME
struct FU {
	vi u;
	FU(int n) : u(n + 1) {iota(u.begin(), u.end(), 0);}
	int find(int x) {
		if (u[x] == x) return x;
		return u[x] = find(u[x]);
	}
	void onion(int a, int b) {
		u[find(a)] = find(b);
	}
};
#define log l0g_
const int nax = 1e5 + 44, log = 17;
vi graph[nax];
int jump[nax][log];
int in[nax], out[nax];
int dep[nax];
void dfs(int x, int y = 0, int d = 0) {
	dep[x] = d;
	jump[x][0] = y;
	for (int l = 1; l < log; ++l) {
		jump[x][l] = jump[jump[x][l - 1]][l - 1];
	}
	static int timer = 0;
	in[x] = timer++;
	for (int v : graph[x]) if (v != y) {
		dfs(v, x, d + 1);
	}
	out[x] = timer;
}
int go(int x, int dist) {
	forbits(i, dist) x = jump[x][i];
	return x;
}
int coef[nax];
int ans[nax];
void dfs2(int x, int y = 0, int sum = 0){ 
	sum += coef[x];
	ans[x] = sum == 0;
	for (int v : graph[x]) if (v != y) dfs2(v, x, sum);
}
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	FU f(n);
	vpii rest;
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (f.find(a) == f.find(b))
			rest.emplace_back(a, b);
		else {
			f.onion(a, b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	const int root = 1;
	dfs(root);
	for (auto [a, b] : rest) {
		if (dep[a] < dep[b]) swap(a, b);
		if (in[b] <= in[a] && out[b] >= out[a]) {
			int x = go(a, dep[a] - dep[b] - 1);
			coef[x]++;
			coef[a]--;
		}
		else {
			coef[root]++;
			coef[a]--;
			coef[b]--;
		}
	}
	dfs2(root);
	for (int i = 1; i <= n; ++i) printf("%d", ans[i]);
	puts("");
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME