#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, cnt[N]; 
void Main () {
	cin >> n;
	L(i, 0, 100) cnt[i] = 0;
	L(i, 1, n) {
		int w;
		cin >> w;
		cnt[abs (w)] += 1;
	}
	int ns = min(cnt[0], 1);
	L(i, 1, 100) ns += min(cnt[i], 2);
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}