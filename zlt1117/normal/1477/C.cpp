//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define A(x) ((x)%mod)
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
const int maxn=5005;
ll n,x[maxn],y[maxn];
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)x[i]=gi(),y[i]=gi();
}
inline void solve()
{
	printf("1 ");
	int cur=1;vis[1]=1;
	FOR(tt,2,n)
	{
		int d=1;ll maxd=0;
		int i=cur;
		FOR(j,1,n)
		{
			if(!vis[j]&&(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])>maxd)maxd=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]),d=j;
		}
		vis[d]=1;
		printf("%d ",cur=d);
	}
}
int main()
{
 	int T=1;
//	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}