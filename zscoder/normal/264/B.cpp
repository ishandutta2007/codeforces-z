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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[100001];
int dp[100001];
int d[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	dp[0] = 1;
	vi v2;
	for(int j = 1; j*j <= a[0]; j++)
	{
		if(a[0]%j==0)
		{
			v2.pb(j);
			v2.pb(a[0]/j);
		}
	}
	for(int i = 1; i < v2.size(); i++)
	{
		d[v2[i]] = 1;
	}
	for(int i = 1; i < n; i++)
	{
		vi vec;
		for(int j = 1; j*j <= a[i]; j++)
		{
			if(a[i]%j==0)
			{
				vec.pb(j);
				vec.pb(a[i]/j);
			}
		}
		for(int j = 1; j < vec.size(); j++)
		{
			dp[i] = max(dp[i], d[vec[j]]+1);
		}
		for(int j = 1; j < vec.size(); j++)
		{
			d[vec[j]] = max(d[vec[j]], dp[i]);
		}
		//cerr << dp[i] << '\n';
	}
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
	cout<<ans;
}