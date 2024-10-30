#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a[100001];
const int MOD = 10007;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;  cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = (ans + (a[i]*a[n-1-i])%MOD)%MOD;
	}
	ans=(ans+MOD)%MOD;
	cout << ans << '\n';
}