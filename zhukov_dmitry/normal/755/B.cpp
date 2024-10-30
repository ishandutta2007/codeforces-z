#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

int n, m;
MSI w;
int a[2024];
char s[102400];
int c[2024];
bool u[2024];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	int k = 0;
	clr(c);
	clr(u);
	forn(i, n + m)
	{
		scanf("%s", s);
		if (!w.count(s)) w[s] = k++;
		a[i] = w[s];
		c[a[i]]++;
	}
	int cur = 0;
	for(;;)
	{
		int l = cur ? n : 0;
		int r = cur ? n + m - 1 : n - 1;
		int f = -1;
		For(t, l, r)
		{
			if (u[a[t]]) continue;
			if (c[a[t]] == 1)
			{
				f = t;
				break;
			}
		}
		For(t, l, r)
		{
			if (u[a[t]]) continue;
			if (c[a[t]] == 2)
			{
				f = t;
				break;
			}
		}
		u[a[f]] = true;
		if (f < 0)
		{
			puts(cur ? "YES" : "NO");
			return 0;
		}
		cur = 1 - cur;
	}
	
	return 0;
}