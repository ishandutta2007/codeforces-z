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
typedef pair<ll, ll> pii;
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

string calc(string s){
	int n = s.size();
	REP(i, n-2){
		if(s[i] == '1' && s[i+1] == '0' && s[i+2] == '0'){
			s[i] = '0';
			s[i+1] = '1';
			s[i+2] = '1';
			int j=i-2;
			while(0<=j && s[j] == '1' && s[j+1] == '0' && s[j+2] == '0'){
				s[j] = '0';
				s[j+1] = '1';
				s[j+2] = '1';
				j -= 2;
			}
		}
	}
	REP(i, n) if(s[i] == '1') return s.substr(i);
	return "";
}
main(){
	string s, t;
	cin >> s;
	string res = calc(s);
	cin >> s;
	string res2 = calc(s);
	if(res == res2) puts("=");
	else if(res.size() == res2.size()) puts((res < res2) ? "<" : ">");
	else puts((res.size() < res2.size()) ? "<" : ">");
	return 0;
}