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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	if(n>m)
	{
		cout<<"YES";
	}
	else if(n<m)
	{
		cout<<"NO";
	}
	else
	{
		set<string> s;
		for(int i = 0; i < n; i++)
		{
			string a; cin>>a;
			s.insert(a);
		}
		for(int i = 0; i < m; i++)
		{
			string a; cin>>a;
			s.insert(a);
		}
		int u = n+m-s.size(); 
		if(u&1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
}