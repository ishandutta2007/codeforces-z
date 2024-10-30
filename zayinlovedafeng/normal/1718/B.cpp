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

#define maxn 105
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

const int m = 60;
int n;
LL a[maxn], A;
LL f[maxn], s[maxn];
int color[maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  f[0] = f[1] = 1;
  for (int i = 2; i <= m; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  for (int i = s[0] = 1; i <= m; ++i) s[i] = s[i - 1] + f[i];
  int _;
  read(_);
  while (_--) {
    A = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], A += a[i];

    auto solve = [&]() {
      int cnt = -1;
      for (int i = 0; i <= m; ++i)
        if (A == s[i]) cnt = i;
      // dbg(cnt);
      if (!~cnt) return false;
      int last = 0;
      for (int turn = cnt; turn >= 0; --turn) {
        int now = -1;
        for (int i = 1; i <= n; ++i) {
          if (i == last) continue;
          if ((!~now && a[i] >= f[turn]) || (~now && a[i] >= a[now])) {
            now = i;
          }
        }
        // dbg(turn, now, a[now], f[turn]);
        if (!~now) return false;
        a[now] -= f[turn];
        color[turn] = now;
        last = now;
      }
      for (int i = 1; i <= cnt; ++i)
        if (color[i] == color[i - 1]) return false;
      // for (int i = 0; i <= cnt; ++i) cout << color[i] << " ";
      // cout << endl;
      return true;
    };
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/