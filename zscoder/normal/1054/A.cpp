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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x,y,z,t1,t2,t3;
	cin>>x>>y>>z>>t1>>t2>>t3;
	int s1 = abs(x-y)*t1;
	int s2 = abs(z-x)*t2+abs(x-y)*t2+t3*3;
	if(s2<=s1) cout<<"YES\n";
	else cout<<"NO\n";
}