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
const int maxn=2e5+5;
int n,a[maxn];
int vis[maxn];
inline void init()
{
	FOR(i,0,2*n+2)vis[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),vis[a[i]]++;
}
inline void solve()
{
	for(int i=2*n;i>=1;--i)
	{
		if(vis[i]==2)vis[i]--,vis[i+1]++;
		else if(vis[i+1]==0&&vis[i])vis[i]--,vis[i+1]++;
	}
	int ans=0;
	FOR(i,0,2*n+2)ans+=vis[i]>0;
	printf("%d\n",ans);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}