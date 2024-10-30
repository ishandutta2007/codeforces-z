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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, k, nm;
int b[82][82];
VI a[82 * 82 + 2];
int e[82 * 82 * 16 + 100][5];
int d[82 * 82 + 2];
int pa[82 * 82 + 2];
int po[82 * 82 + 2];
bool u[82 * 82 + 2];

void add_edge(int v1, int v2, int cc, int w)
{
	e[k][0] = v1;
	e[k][1] = v2;
	e[k][2] = cc;
	e[k][3] = 0;
	e[k][4] = w;
	a[v1].pb(k);
	k++;
	e[k][0] = v2;
	e[k][1] = v1;
	e[k][2] = 0;
	e[k][3] = 0;
	e[k][4] = -w;
	a[v2].pb(k);
	k++;
}

int find(int st, int en)
{
	memset(d, 0x3f, sizeof(d));
	d[st] = 0;

	priority_queue < PII, vector < PII >, greater < PII > > q;
	clr(u);
	q.push(mp(d[st], st));
	while (!q.empty())
	{
		PII tmp = q.top();
		q.pop();
		int v = tmp.second;
		int dd = tmp.first;
		if (u[v]) continue;
		u[v] = true;
		forn(i1, a[v].sz)
		{
			int i = a[v][i1];
			int v2 = e[i][1];
			if (e[i][2] > e[i][3] && d[v2] > dd + e[i][4] + po[v] - po[v2])
			{
				d[v2] = dd + e[i][4] + po[v] - po[v2];
				pa[v2] = i;
				q.push(mp(d[v2], v2));
			}
		}
	}

	forn(i, en + 1)
	{
		po[i] += d[i];
	}

	return d[en];
}

int flow(int st, int en)
{
	int ans = 0;

	clr(po);
	forn(i, nm/2)
	{
		int x = find(st, en);
		cerr << "x = " << x << endl << flush;
		int t = en;
		while (t != st)
		{
			int q = pa[t];
			ans += e[q][4];
			e[q][3]++;
			e[q ^ 1][3]--;
			t = e[q][0];
		}
	}

	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		forn(j, m)
		{
			scanf("%d", &b[i][j]);
		}
	}
	k = 0;
	nm = n * m;
	int st = nm;
	int en = st + 1;
	forn(i, n)
	{
		forn(j, m)
		{
			forn(l, 4)
			{
				int x = i + dx[l];
				int y = j + dy[l];
				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				add_edge((i * m + j), (x * m + y), 1, b[i][j] != b[x][y]);
			}
			if ((i + j) & 1) add_edge(st, (i * m + j), 1, 0);
			else add_edge((i * m + j), en, 1, 0);
		}
	}
	
	int ans = flow(st, en);

	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}