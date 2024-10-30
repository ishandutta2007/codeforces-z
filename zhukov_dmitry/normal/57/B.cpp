#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, m, k;
int a[102400][4];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t t0 = clock();
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d", &n, &m, &k);
	forn(i, m)
	{
		forn(j, 3)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	i64 ans = 0;
	forn(tt, k)
	{
		int x;
		scanf("%d", &x);
		
		forn(i, m)
		{
			if (a[i][0] <= x && a[i][1] >= x)
			{
				ans += a[i][2] + (x - a[i][0]);
			}
		}
		
	}
	cout << ans << endl;

#ifdef ROOM_311
	time_t t1 = clock();
	fprintf(stderr, "execution time = %ld ms\n", (t1 - t0) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}