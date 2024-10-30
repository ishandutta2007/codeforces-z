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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int a[3]; cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	ll ans = a[0];
	if(a[2]-a[1]>=a[0])
	{
		a[2]-=a[0];
		ans+=min(a[1],a[2]);
	}
	else
	{
		ll cur = a[0]-(a[2]-a[1]);
		a[2]=a[1];
		ans+=a[1]-(cur+1)/2;
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}