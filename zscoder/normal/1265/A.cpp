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
	string s; cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='?') continue;
		set<char> S = {'a','b','c'};
		if(i>0) S.erase(s[i-1]);
		if(i+1<s.length()) S.erase(s[i+1]);
		s[i]=(*S.begin());
	}
	for(int i=1;i<s.length();i++)
	{
		if(s[i]==s[i-1]){cout<<-1<<'\n'; return ;}
	}
	cout<<s<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}