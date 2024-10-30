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

vi adj[301111];
int vis[301111];
int ans[301111];

void solve()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; adj[u].pb(v); adj[v].pb(u);
	}
	queue<int> q;
	q.push(0);
	bool pos=1;
	ans[0]=1; vis[0]=1;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v:adj[u])
		{
			//cerr<<"EX "<<u<<' '<<v<<'\n';
			if(ans[v]==1)
			{
				ans[u]=0;
			}
		}
	//	cerr<<"IN Q: "<<u<<' '<<ans[u]<<'\n';
		if(ans[u]==-1) ans[u]=1;
		//push to queue
		for(int v:adj[u])
		{
			if(!vis[v])
			{
				vis[v]=1; q.push(v);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			cout<<"NO\n"; pos=0; break;
		}
	}
	if(pos)
	{
		vi chosen;
		for(int i=0;i<n;i++)
		{
			if(ans[i]) chosen.pb(i);
		}
		cout<<"YES\n";
		cout<<chosen.size()<<'\n';
		for(int v:chosen)
		{
			cout<<v+1<<' ';
		}
		cout<<'\n';
	}
	for(int i=0;i<n;i++) adj[i].clear();
	for(int i=0;i<n;i++) vis[i]=0,ans[i]=-1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(ans,-1,sizeof(ans));
	int t; cin>>t;
	while(t--) solve();
}