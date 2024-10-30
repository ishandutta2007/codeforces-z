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
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m;
main(){
	scanf("%d", &n);
	vi d(n);
	REP(i, n) scanf("%d", &d[i]);
	if(n <= 2){
		printf("%d\n", n);
		return 0;
	}
	vi dp1(n, 1);
	vi dp2(n, 1);
	int ans = 0;
	REP(i, n){
		if(i+1 < n){
			if(d[i] < d[i+1]){
				chmax(dp1[i+1], dp1[i] + 1);
				chmax(dp2[i+1], dp2[i] + 1);
			}
			if(0 < i && d[i-1]+1 < d[i+1]) chmax(dp2[i+1], dp1[i-1] + 2);
			if(i+2 < n && d[i]+1 < d[i+2]) chmax(dp2[i+2], dp1[i  ] + 2);
		}
		chmax(ans, dp1[i]+1);
		chmax(ans, dp2[i]);
	}
	printf("%d\n", min(ans, n));
	return 0;
}