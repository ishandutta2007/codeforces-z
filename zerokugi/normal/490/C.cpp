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


string s;
ll a, c;

main(){
	cin >> s >> a >> c;
	int n = s.size();
	vi d(n+1, 1);
	ll b = 0;
	REP(i, n){
		b = b*10 + s[i]-'0';
		if(b%=a) d[i+1] = 0;
	}
	b = 0; 
	ll t = 1;
	RREP(i, n){
		b = b + (s[i]-'0') * t;
		if((b%=c) || s[i] == '0') d[i] = 0;
		t = t * 10 % c; 
	}
	for(int i=1;i<n;i++) if(d[i]){
		cout << "YES" << endl;
		string a = s.substr(0, i);
		cout << a << endl;
		a = s.substr(i);
		cout << a << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}