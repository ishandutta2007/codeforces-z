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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	vi a; int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; a.pb(x);
	}
	set<int> S;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			S.insert(a[j]-a[i]);
		}
	}
	cout<<S.size()<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}