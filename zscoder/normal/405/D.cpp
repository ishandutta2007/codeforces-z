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

bool used[1000001];
vi vec;
const int s = 1000001;
vi ans;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vec.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> vec[i];
		used[vec[i]] = true;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(used[s - vec[i]]) cnt++;
		else ans.pb(s-vec[i]);
	}	
	cnt>>=1;
	int j = 1;
	for(int i = 0; i < cnt; i++)
	{
		while(used[j]||used[s-j]) j++;
		ans.pb(j); ans.pb(s-j);
		j++;
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}