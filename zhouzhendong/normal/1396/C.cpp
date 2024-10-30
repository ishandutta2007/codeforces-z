#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//int md(LL x){
//	return (x%mod+mod)%mod;
//}
const int N=1000005;
const LL INF=1e18;
int n;
LL r1,r2,r3,d;
LL a[N];
LL calc0(LL a){
	return min(r3+a*r1,INF);
}
LL calc1(LL a){
	return min(r2,(a+1)*r1)+r1;
}
LL g[N];
LL f[N];
int main(){
	n=read(),r1=read(),r2=read(),r3=read(),d=read();
	For(i,1,n)
		a[i]=read();
	For(i,0,N-1)
		g[i]=f[i]=INF;
	g[0]=0;
	For(i,1,n){
		ckmin(g[i],g[i-1]+d+calc0(a[i]));
		ckmin(g[i],f[i-1]+d*2+calc0(a[i]));
		ckmin(f[i],g[i-1]+d*2+calc1(a[i]));
		ckmin(g[i],f[i-1]+d*2+calc1(a[i]));
	}
	LL ans=min(g[n],f[n]+d);
	ckmin(ans,f[n-1]+calc0(a[n])+d);
	cout<<ans-d<<endl;
	return 0;
}