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

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
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
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

#define x first
#define y second

int n, m, k;
string a[2024];
int b[2024];
char s[1024000];
PII d[2024][2024];
int next[26][2024][2];
vector < int > pos[26][2024];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	        
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%s", s);
		int l = strlen(s);
		forn(j, l)
		{
			int c = s[j] - 'a';
			pos[c][i].pb(j);
		}
		a[i] = s;
	}
	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%d", &b[i]);
		b[i]--;
	}
	scanf("%s", s);
	k = strlen(s);
	memset(next, 0x3f, sizeof(next));
	ford(i, m - 1)
	{
		forn(c, 26)
		{
			int r = b[i + 1];
			if (pos[c][r].sz)
			{
				next[c][i][0] = i + 1;
				next[c][i][1] = pos[c][r][0];
			}
			else
			{
				next[c][i][0] = next[c][i + 1][0];
				next[c][i][1] = next[c][i + 1][1];
			}
		}
	}

	memset(d, 0x3f, sizeof(d));
	d[0][0] = mp(0, 0);
	For(i, 1, k)
	{
		forn(j, i + 1)
		{
			d[i][j] = min(d[i][j], d[i-1][j]);
			if (j > 0)
			{
				int c = s[i - 1] - 'a';
				int x = d[i-1][j-1].x;
				int y = d[i-1][j-1].y;
				if (x >= INF || y >= INF) continue;
				int r = lower_bound(pos[c][b[x]].begin(), pos[c][b[x]].end(), y) - pos[c][b[x]].begin();
				if (r == (int)pos[c][b[x]].sz)
				{
					d[i][j] = min(d[i][j], mp(next[c][x][0], next[c][x][1] + 1));
				}
				else
				{
					d[i][j] = min(d[i][j], mp(x, pos[c][b[x]][r] + 1));
				}
			}
		}
	}

	int ans = 0;
	ford(i, k + 1)
	{
		if (d[k][i].x < INF)
		{
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}