#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int b,g,n;
	cin>>b>>g>>n;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int x=i;
		int y=n-i;
		if(x<=b&&y<=g)
		{
			ans++;
		}
	}
	cout<<ans<<'\n';	
}