#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rint(x);
#define rfloat(x) scanf("%lf", &(x))

#ifndef ONLINE_JUDGE
const bool DEBUG = true;
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
#else
const bool DEBUG = false;
#define Db(x...)
#endif

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c,r=0,n=0;
	x=0;
	for (ever)
	{
		c=getchar();
		if ((c<0) && (!r))
			return(0);
		else if ((c=='-') && (!r))
			n=1;
		else if ((c>='0') && (c<='9'))
			x=x*10+c-'0',r=1;
		else if (r)
			break;
	}
	if (n)
		x=-x;
	return(1);
}

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;

ll mpw(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b % 2) ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

ll N, M, K, extra, leftOver;
const int MX = 102;
ll dp[MX][MX*MX];
ll pasc[MX][MX];
ll powTable[MX][2];

ll f(int pos, int filled)
{
	if (filled > K) return 0;
	if (pos == N) return filled == K;
	ll& ans = dp[pos][filled];
	if (ans >= 0) return ans;
	ans = 0;
	ji(N+1)
	{
		ans += f(pos+1, filled + i) * powTable[i][pos < leftOver] % MOD;
		if (ans >= MOD) ans -= MOD;
	}
	return ans;
}

int main()
{
	memset(dp, -1, sizeof dp);
	jij(MX, MX)
	{
		if (j == 0) pasc[i][j] = 1;
		else if (j > i) pasc[i][j] = 0;
		else pasc[i][j] = (pasc[i-1][j-1] + pasc[i-1][j]) % MOD;
	}
	rint(N);
	rint(M);
	rint(K);
	extra = M / N;
	leftOver = M % N;
	ji(N+1)
	{
		powTable[i][0] = mpw(pasc[N][i], extra);
		powTable[i][1] = mpw(pasc[N][i], extra + 1);
	}
	printf("%lld\n", f(0, 0));
}