#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, k, f[N];
void Main() {
	cin >> n >> k;
	L(i, 1, 2 * k - n - 1) cout << i << " ";
	R(i, k, 2 * k - n) cout << i << " ";
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main(); 
	return 0;
}