#include<stdio.h>
#include<bitset>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<math.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<functional>
#include<unordered_map>
#include<list>
#define E2(x,y) return !printf(x, y)
#define E1(x) return !printf(x)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int,int,int> t3;

const int MM = 1000;

ll sq(ll x){ return x*x; }
ll rv(ll x){ ll su = 0; while(x){ su = su*10 + x%10; x /= 10; } return su; }

ll pw(ll a, ll b){
	if( !b ) return 1;
	return pw(a*a % MM, b/2) * (b%2 == 1? a : 1) % MM;
}

ll pw(ll a, ll b, ll c){
	if( !b ) return 1;
	return pw(a*a % c, b/2) * (b%2 == 1? a : 1) % c;
}

//ll rv(ll a){ return pw(a, MM-2); }

int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int Ox[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int Oy[8] = {2, 1, -2, -1, -2, -1, 2, 1}; 
int Bx[6] = {-1, -1, 0, 1, 1, 0};
int By[6] = {-1, 0, 1, 1, 0, -1};

ll gcd(ll A, ll B){ return A? gcd(B%A, A) : B;}

pii operator*(const pii &l, const ll &r){
	return pii(l.first * r, l.second * r);
}

pii operator*(const pii &l, const pii &r){
	return pii(l.first * r.first, l.second * r.second);
}

pii operator+(const pii &l, const pii &r){
	return pii(l.first + r.first, l.second + r.second);
}

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

pii operator%(const pii &l, const pii &r){
	return pii(l.first % r.first, l.second % r.second);
}

ll operator^(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

ll size(pii c){ return sq(c.first) + sq(c.second); }

void file(char* name){
	char buf[105];
	sprintf(buf, "%s.in", name);
	freopen(buf,"r", stdin);
	sprintf(buf, "%s.out", name);
	freopen(buf,"w", stdout);
}

int coor(vector<int> &L, int x){
	return lower_bound(L.begin(), L.end(), x) - L.begin();
}

const int MX = 200005;
const double PI = acos(-1);

auto cmp = [](const pii &l, const pii &r){return l.second !=r.second? l.second < r.second : l.first < r.first; };

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f, g, h;

int D[MX], vst[MX];
char A[MX], B[MX];

int main()
{
	scanf("%s%s", A+1, B+1);
	N = strlen(A+1);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	int s = 0, e = N, m;
	while(s <= e){
		m = (s+e) / 2;
		string X;
		for(int i = 1; i <= N; i++) vst[i] = 0;
		for(int i = 1; i <= m; i++){
			vst[D[i]] = 1;
		}
		for(int i = 1; i <= N; i++) if( vst[i] == 0 ) X += A[i];
		int wi = 1, ch = 0;
		for(char c : X){
			if( c == B[wi] ) wi++;
			if( !B[wi] ) ch = 1;
		}
		if( ch ) s = m+1;
		else e = m-1;
	}
	swap(s, e);
	printf("%d", s);
}