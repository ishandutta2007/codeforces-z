#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int mod=1e9+7,maxn=4e5+20;
int n;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
class mint
{
	public:
	int v;
	mint():v(0){}
	mint(int _v):v(_v){}
	mint& operator +=(const mint &rhs){v+=rhs.v;if(v>=mod)v-=mod;return *this;}
	mint& operator -=(const mint &rhs){v-=rhs.v;if(v<0)v+=mod;return *this;}
	mint& operator *=(const mint &rhs){v=(ll)v*rhs.v%mod;return *this;}
	mint& operator /=(const mint &rhs){v=(ll)v*rhs.inv()%mod;return *this;}
	mint operator -(){return v?mod-v:0;}
	friend mint operator +(const mint &lhs,const mint &rhs){return (mint)lhs+=rhs;}
	friend mint operator -(const mint &lhs,const mint &rhs){return (mint)lhs-=rhs;}
	friend mint operator *(const mint &lhs,const mint &rhs){return (mint)lhs*=rhs;}
	friend mint operator /(const mint &lhs,const mint &rhs){return (mint)lhs/=rhs;}
	int inv()const{return qpow(v,mod-2);}
};
mint fac[maxn],inv[maxn];
mint C(int n,int m){if(n<m)return 0;return fac[n]*inv[m]*inv[n-m];}
mint ans;
int main()
{
	n=4e5+5;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	inv[n]=fac[n].inv();
	for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1);
	n=read();
	for(int i=0;i<=n;i++)
		ans+=C(i+read(),i+1);
	printf("%d\n",ans.v);
}