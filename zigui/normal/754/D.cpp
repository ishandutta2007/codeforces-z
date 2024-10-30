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
typedef pair<int,int> pii;

const int MM = 1000000007;

ll sq(ll x){ return x*x; }

ll pw(ll a, ll b){
	if( !b ) return 1;
	return pw(a*a % MM, b/2) * (b%2 == 1? a : 1) % MM;
}

ll pw(ll a, ll b, ll c){
	if( !b ) return 1;
	return pw(a*a % c, b/2) * (b%2 == 1? a : 1) % c;
}

//ll rv(ll a){ return pw(a, MM-2); }

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int Ox[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int Oy[8] = {2, 1, -2, -1, -2, -1, 2, 1}; 

ll gcd(ll A, ll B){ return A? gcd(B%A, A) : B;}

pii operator+(const pii &l, const pii &r){
	return pii(l.first + r.first, l.second + r.second);
}

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

ll operator^(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

ll size(pii c){ return sq(c.first) + sq(c.second); }

void file(){
	freopen("lasers.in","r", stdin);
	freopen("lasers.out", "w", stdout);
}

int coor(vector<int> &L, int x){
	return lower_bound(L.begin(), L.end(), x) - L.begin();
}

const int MX = 1<<20;

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f;

struct cell{
	int s, e, d;
	bool operator<(const cell &l)const{
		return s != l.s? s < l.s : e < l.e;
	}
}D[MX];

struct tree{
	int t[MX*2];
	int update(int x, int v){
		x += MX;
		while(x){
			t[x] += v; x /= 2;
		}
	}
	int read(int P){
		int x = 1;
		while(x < MX){
			if( t[x*2+1] < P ){
				P -= t[x*2+1]; x = x*2;
			}
			else x = x*2+1;
		}
		return x - MX;
	}
} tree;

int main()
{
	vector<int> X;
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++){
		scanf("%d%d", &D[i].s, &D[i].e);
		D[i].e++;
		X.push_back(D[i].s);
		X.push_back(D[i].e);
		D[i].d = i;
	}
	sort(D+1, D+N+1);
	sort(X.begin(), X.end());
	for(int i = 1; i <= N; i++){
		D[i].s = coor(X, D[i].s);
		D[i].e = coor(X, D[i].e);
	}

	int ans = 0, p = 0, e = 0;
	for(int i = 1; i <= N; i++){
		tree.update(D[i].e, 1);
		int x = tree.read(K);
		if( x > D[i].s ){
			if( ans < X[x] - X[D[i].s] ){
				p = D[i].s; e = x;
				ans = X[x] - X[D[i].s];
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 1, j = 1; i <= N && j <= K; i++){
		if( ans == 0 || D[i].s <= p && e <= D[i].e ){
			printf("%d ", D[i].d);
			j++;
		}
	}
}