#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i, begin, end)                                \
  for (__typeof(begin) i = (begin), _end = (end),         \
                       _step = 1 - 2 * ((begin) > (end)); \
       i != _end; i += _step)

// OUTPUT
template <class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  if (!v.size())
    os << "]";
  else
    for (int i = 0; i < v.size(); ++i) os << v[i] << ",]"[i == v.size() - 1];
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  if (!s.size())
    os << "}";
  else
    for (auto x : s) os << x << ",}"[x == *s.rbegin()];
  return os;
}

void printr(ostream& os) { os << '\n'; }
template <class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << " ";
  printr(os, args...);
}
#define print(args...) printr(cout, ##args)

// INPUT
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T, class... Args>
void read(T& t, Args&... args) {
  read(t), read(args...);
}
template <class T>
void readarray(T* A, int n) {
  rep(i, 0, n) read(A[i]);
}

// DEBUG
void dbgr(ostream& os) { os << endl; }
template <class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << ", ";
  dbgr(os, args...);
}
#define dbg(args...) \
  cout << #args << " = ", dbgr(cout, ##args)  // cout can be changed

#define maxn 500050
#define modu 998244353
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

// COMMON FUNCTION
// random LL
LL randll(LL a, LL b) {
  uniform_int_distribution<int> u(a, b);
  static mt19937 e(time(0));
  return u(e);
}

LL pw(LL a, LL k = modu - 2) {
  LL ans = 1;
  for (a %= modu; k; k >>= 1) {
    if (k & 1) ans = ans * a % modu;
    a = a * a % modu;
  }
  return ans;
}

int n, m;
int a[maxn];

int mnR[maxn];

vector<int> G[maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  read(_);
  while (_--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) mnR[i] = i;
    for (int i = 1; i <= m; ++i) {
      int l, r;
      cin >> l >> r;
      mnR[l] = max(mnR[l], r);
    }
    for (int i = 2; i <= n; ++i) {
      mnR[i] = max(mnR[i], mnR[i - 1]);
    }

    int lim = n;
    set<int> pos;
    map<int, vector<int>> last;
    for (int i = n; i; --i) {
      vector<int>& v = last[a[i]];
      v.push_back(i);
      int rk = upper_bound(v.rbegin(), v.rend(), mnR[i]) - v.rbegin() - 1;
      //   dbg(i, mnR[i], rk, v);
      if (rk) {
        lim = min(lim, v[v.size() - 2]);
        int j = v[v.size() - rk - 1];
        // dbg(i, j);
        pos.insert(i);
        G[i].push_back(j);
      }
    }

    // dbg(lim);

    if (!pos.size()) {
      cout << 0 << endl;
    } else {
      int ans = n;
      for (int l = 1; l <= lim; ++l) {
        ans = min(ans, *pos.rbegin() - l + 1);
        // dbg(l, pos, G[l]);
        if (G[l].size()) {
          assert(pos.count(l));
          pos.erase(l);
          for (int j : G[l]) {
            pos.insert(j);
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/