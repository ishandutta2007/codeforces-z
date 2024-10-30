#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 200100;
int a[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
    {
        cin >> a[i];
        a[i] += i;
    }
    sort(a, a + n);
    forn (i, n - 1)
        if (a[i] == a[i + 1])
        {
            cout << ":(\n";
            return 0;
        }
    forn (i, n)
        cout << a[i] - i << ' ';
    cout << '\n';
    return 0;
}