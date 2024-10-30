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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}
	
string s,t;
int dp[3011][3011][2];
int n,m;

bool match(int x, int y) //match s[x] and t[y])
{
	if(y<0) return 0;
	if(y>=m) return 1;
	return (s[x]==t[y]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>s>>t;
	n=s.length(); m=t.length();
	if(n==1)
	{
		if(s[0]!=t[0])
		{
			cout<<0<<'\n';
		}
		else
		{
			cout<<2<<'\n';
		}
		return 0;
	}
	dp[n-1][1][1]=match(n-1,0);
	dp[n-1][0][1]=match(n-1,n-1);
	if(m<n) dp[n-1][0][0]=1;
	for(int i=n-1;i>0;i--)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(!dp[i][j][k]) continue;
				int v=dp[i][j][k];
				//add current char to front
				if(match(i-1,j)) radd(dp[i-1][j+1][1],v);
				//add current char to back
				if(match(i-1,i-1+j)) radd(dp[i-1][j][1],v);
				//blind
				if(i-1<=m-1) continue; //no more blind
				if(!k)
				{
					radd(dp[i-1][j][k],v);
				}
				//cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++) 
	{
		radd(ans,dp[0][i][1]);
	}
	cout<<ans<<'\n';
}