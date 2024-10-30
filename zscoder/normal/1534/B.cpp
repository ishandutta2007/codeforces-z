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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;



void solve()
{
	int n; cin>>n;
	vi a;
	a.pb(0);
	for(int i=0;i<n;i++) 
	{
		ll x; cin>>x; a.pb(x);
	}
	a.pb(0);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
		{
			ll mx = max(a[i-1],a[i+1]);
			ans+=a[i]-mx; a[i]=mx;
		}
	}
	for(int i=1;i<=n+1;i++) ans+=abs(a[i]-a[i-1]);
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}