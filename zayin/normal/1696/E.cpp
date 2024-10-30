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
#define modu 1000000007
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

int n, a[maxn];

LL F[maxn], FI[maxn], I[maxn];

LL C(int n, int m) { return F[n] * FI[m] % modu * FI[n - m] % modu; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  F[0] = FI[0] = I[1] = I[0] = 1;
  for (int i = 1; i < maxn; ++i) F[i] = F[i - 1] * i % modu;
  for (int i = 2; i < maxn; ++i) I[i] = modu - modu / i * I[modu % i] % modu;
  for (int i = 1; i < maxn; ++i) FI[i] = FI[i - 1] * I[i] % modu;
  cin >> n;
  for (int i = 0; i <= n; ++i) cin >> a[i];

  if (a[0] == 0) {
    cout << 0 << endl;
    return 0;
  }

  LL ans = modu - 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = a[i + 1]; j < a[i]; ++j) {
      ans = (ans + C(j + i, i)) % modu;
      // ps.emplace(j, i + 1);
    }
    if (a[i]) {
      ans = (ans + C(a[i] - 1 + i, i)) % modu;
    }
    // ps.emplace(a[i], i);
  }
  cout << ans << endl;
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/