#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (i / 2 + j / 2 + i % 2 + j % 2) % 2 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}