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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

vi adj[1111];
int par[1111];
bool good;

void dfs(int u)
{
	bool leaf=1; int cnt=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		dfs(v); leaf=0;
		if(adj[v].empty()) cnt++;
	}
	if(!leaf&&cnt<3)
	{
		good=0; 
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>par[i]; par[i]--;
		adj[par[i]].pb(i);
	}
	good=1;
	dfs(0);
	cout<<(good?"Yes":"No")<<'\n';
}