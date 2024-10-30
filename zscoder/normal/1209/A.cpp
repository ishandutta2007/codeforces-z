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

int a[333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; a[x]++;
	}
	int s=0;
	for(int i=1;i<=200;i++)
	{
		if(a[i]>0)
		{
			s++;
			for(int j=i;j<=200;j+=i)
			{
				a[j]=0;
			}
		}
	}
	cout<<s<<'\n';
}