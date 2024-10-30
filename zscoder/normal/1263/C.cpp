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
	int n; cin>>n;
	set<int> S; S.insert(0);
	for(int i=1;i<=100000;i++) S.insert(n/i);
	for(int i=1;i<=100000;i++)
	{
		int r=n/i;
		int l=(n+1+i)/(i+1);
		if(l<=r) S.insert(i);
	}
	cout<<S.size()<<'\n';
	for(int x:S) cout<<x<<' ';
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}