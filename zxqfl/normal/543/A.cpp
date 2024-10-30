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

int N, M, B, V;

const int MX = 510;

ll** mk()
{
	ll** ans = new ll*[MX];
	ji(MX)
	{
		ans[i] = new ll[MX];
		jj(MX) ans[i][j] = 0;
	}
	return ans;
}

ll** dp1 = mk();
ll** dp2 = mk();
int arr[MX];

int main()
{
	rint(N);	
	rint(M);	
	rint(B);
	rint(V);
	ji(N) rint(arr[i]);
	dp1[0][0] = 1;
	jk(N)
	{
		jij(M + 1, B + 1)
		{
			dp2[i][j] = 0;
			if (i && j >= arr[k])
				dp2[i][j] += dp2[i-1][j-arr[k]];
			dp2[i][j] += dp1[i][j];
			dp2[i][j] %= V;
		}
		swap(dp1, dp2);
	}
	ll ans = 0;
	ji(B + 1) ans += dp1[M][i];
	ans %= V;
	printf("%lld\n", ans);
}