//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1005;
int a[maxn],n,cnt[maxn];
vector<int>ans;
bool vis[maxn];
inline void init()
{
	ans.clear();
	FOR(i,0,n)vis[i]=0;
}
inline int mex()
{
	FOR(i,0,n)cnt[i]=0;
	FOR(i,0,n-1)cnt[a[i]]++;
	FOR(i,0,n)if(cnt[i]==0)return i;
	return n;
}
inline void input()
{
	n=gi();
	FOR(i,0,n)cnt[i]=0;
	FOR(i,0,n-1)a[i]=gi();
}
inline void solve()
{
	int x=mex();
	while(x!=n)
	{
		a[x]=x;
		ans.pb(x);
		x=mex();
		vis[x]=1;
	}
	FOR(i,0,n-1)
	{
		if(a[i]!=i)
		{
			ans.pb(i);
			a[i]=mex();
			int x=mex();
			while(1)
			{
				a[x]=x;
				ans.pb(x);
				if(x==i)break;
				x=mex();
			}
		}
	}
	printf("%d\n",sz(ans));
	for(auto x:ans)printf("%d ",x+1);
	printf("\n");
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}