#include <stdio.h>
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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vi x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vi s;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
      s.push_back(x[j] - x[i]);
    }
    sort(s.begin(), s.end());
    int res = unique(s.begin(), s.end()) - s.begin();
    cout << res << '\n';
  }
  return 0;
}