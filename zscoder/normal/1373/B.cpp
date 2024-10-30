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

void solve()
{
	string s; cin>>s;
	int n=s.length();
	int cnt=0;
	while(1)
	{
		string t;
		int id=-1;
		for(int i=0;i+1<s.length();i++)
		{
			if(s[i]!=s[i+1])
			{
				id=i;
			}
		}
		if(id==-1) break;
		t=s.substr(0,id);
		if(id+2<s.length()) t+=s.substr(id+2,int(s.length())-(id+2));
		cnt++;
		s=t;
	}
	cout<<((cnt&1)?"DA":"NET")<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}