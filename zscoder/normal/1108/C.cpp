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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

char C[3]={'R','G','B'};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	map<char,int> ma;
	for(int i=0;i<3;i++) ma[C[i]]=i;
	int mn=int(1e9); string ans="";
	vi p = {0,1,2};
	do
	{
		string res=""; int as=0;
		for(int i=0;i<n;i++)
		{
			res+=C[p[i%3]];
			if(res[i]!=s[i]) as++;
		}
		if(as<mn)
		{
			mn=as;ans=res;
		}
	}while(next_permutation(p.begin(),p.end()));
	cout<<mn<<'\n'<<ans<<'\n';
}