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
	int n; cin>>n;
	int cur=1;
	for(int i = 1; i <= 10000; i++)
	{
		if((i*(i+1))/2 <= n)
		{
			cur=i;
		}
		else break;
	}
	cout<<cur<<'\n';
	for(int i = 1; i < cur; i++)
	{
		cout<<i<<' ';
	}
	cout<<n - (cur*(cur+1))/2 + cur;
}