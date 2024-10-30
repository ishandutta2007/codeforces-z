#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

ll c2(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    int n, d;
    cin >> n >> d;
    vi v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    ll res = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        while (last < n && v[last] - v[i] <= d) {
            ++last;
        }
        res += c2(max(0, last - i - 1));
    }
    cout << res << endl;
    return 0;
}