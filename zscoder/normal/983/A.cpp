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
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<ii,bool> ma;

bool getgc(ll a, ll b)
{
	if(a==1) return true;
	if(ma.find(mp(a,b))!=ma.end()) return ma[mp(a,b)];
	ll gd=__gcd(a,b);
	if(gd==1) return false;
	return (ma[mp(a,b)] = getgc(a/gd,gd));
}

void solve(ll p, ll q, ll b)
{
	if(p==0)
	{
		puts("Finite"); return ;
	}
	ll gd = __gcd(p,q);
	p/=gd; q/=gd;
	if(getgc(q,b))
	{
		puts("Finite");
		return ;
	}
	puts("Infinite");
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		ll p,qq,b; 
		scanf("%lld %lld %lld",&p,&qq,&b);
		solve(p,qq,b);
	}
}