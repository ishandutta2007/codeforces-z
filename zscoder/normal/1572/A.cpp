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


struct SCC
{
	const int INF = int(1e9);
	vector<vector<int> > vec;
	int index;
	vector<int> idx;
	vector<int> lowlink;
	vector<bool> onstack;
	stack<int> s;
	vector<int> sccidx;
	int scccnt;
	vi topo;
	
	//lower sccidx means appear later
	void init(int n)
	{
		idx.assign(n,-1);
		index = 0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
		vec.clear();
		topo.clear();
		vec.resize(n);
	}
	
	void addedge(int u, int v) //u -> v
	{
		vec[u].pb(v);
	}
	
	void connect(int u)
	{
		idx[u] = index;
		lowlink[u] = index;
		index++;
		s.push(u);
		onstack[u] = true;
		for(int i = 0; i < vec[u].size(); i++)
		{
			int v = vec[u][i];
			if(idx[v] == -1)
			{
				connect(v);
				lowlink[u] = min(lowlink[u], lowlink[v]);
			}
			else if(onstack[v])
			{
				lowlink[u] = min(lowlink[u], idx[v]);
			}
		}
		if(lowlink[u] == idx[u])
		{
			while(1)
			{
				int v = s.top();
				s.pop();
				onstack[v] = false;
				sccidx[v] = scccnt;
				if(v == u) break;
			}
			scccnt++;
		}
	}
	
	void tarjan()
	{
		for(int i = 0; i < vec.size(); i++)
		{
			if(idx[i] == -1)
			{
				connect(i);
			}
		}
	}
	
	void toposort() //if graph is a DAG and i just want to toposort
	{
		tarjan();
		int n = vec.size();
		topo.resize(n);
		vector<ii> tmp;
		for(int i = 0; i < n; i++)
		{
			tmp.pb(mp(sccidx[i],i));
		}
		sort(tmp.begin(),tmp.end());
		reverse(tmp.begin(),tmp.end());
		for(int i = 0; i < n; i++)
		{
			topo[i]=tmp[i].se;
			if(i>0) assert(tmp[i].fi!=tmp[i-1].fi);
		}
	}
};

int dp[222222];
vi a[222222];
void solve()
{
	int n; cin>>n; 
	SCC scc; scc.init(n);
	for(int i=0;i<n;i++)
	{
		int k; cin>>k;
		for(int j=0;j<k;j++)
		{
			int x; cin>>x; x--;
			scc.addedge(x,i);
			a[i].pb(x);
		}
	}
	scc.tarjan();
	set<int> S;
	for(int i=0;i<n;i++)
	{
		S.insert(scc.sccidx[i]);
	}
	if(S.size()!=n)
	{
		for(int i=0;i<n;i++)
		{
			a[i].clear(); dp[i]=0;
		} 
		cout<<-1<<'\n'; 
		return ;
	}
	vector<ii> topo;
	topo.resize(n);
	vector<ii> tmp;
	for(int i = 0; i < n; i++)
	{
		tmp.pb(mp(scc.sccidx[i],i));
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	int mx=0;
	for(auto x:tmp)
	{
		int i=x.se;
		for(int v:a[i])
		{
			dp[i] = max(dp[i], dp[v]+(i<v)); 
		}
		mx=max(mx,dp[i]);
	}
	cout<<mx+1<<'\n';
	for(int i=0;i<n;i++)
	{
		a[i].clear(); dp[i]=0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}