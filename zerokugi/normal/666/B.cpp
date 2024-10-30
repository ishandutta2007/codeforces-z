#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int n, m;

vector<vector<pii>> calcd(vector<vi> g){
	vector<vector<pii>> d(n);
	REP(i, n)REP(j, n)d[i].eb(INF, j);
	REP(s, n){
		queue<int> q;
		q.push(s);
		d[s][s].first = 0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v : g[u])if(chmin(d[s][v].first, d[s][u].first + 1))q.push(v);
		}
	}
	REP(i, n)REP(j, n) if(d[i][j].first == INF) d[i][j].first = -1;
	return d;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<vi> g(n), rg(n);
	REP(i, m){
		int u, v;
		cin >> u >> v; u--; v--;
		g[u].pb(v);
		rg[v].pb(u);
	}
	auto d1 = calcd(rg);
	auto d2 = calcd(g);
	auto d = d2;
	REP(i, n){
		sort(RALL(d1[i]));
		sort(RALL(d2[i]));
	}
	pair<int, vi> ans(0, vi({0, 1, 2, 3}));
	REP(u, n)REP(v, n)if(u != v && d[u][v].first > 0){
		int c = 2;
		for(auto &it : d1[u]){
			if(!c) break;
			int s, c1; tie(c1, s) = it;
			if(s == u || s == v) continue;
			c --;
			for(auto &jt : d2[v]){
				int t, c2; tie(c2, t) = jt;
				if(t == u || t == v || t == s) continue;
				int dist = c1 + c2 + d[u][v].first;
				ans = max(ans, mp(dist, vi({s, u, v, t})));
				break;
			}
		}
	}
	REP(i, 4) cout << ans.second[i] + 1 << " \n"[i == 3];
	return 0;
}