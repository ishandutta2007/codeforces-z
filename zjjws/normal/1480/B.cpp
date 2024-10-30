#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int N=3e5+3;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
struct Hash
{
    int M;
    int K;
    inline void init(int M_=0,int K_=0){M=M_;K=K_;return;}
    inline int prpr(int x,int y){return 1LL*x*y%M;}
    inline void Hash_line(int *a,int *b,int L){b[0]=0;for(int i=1;i<=L;i++)b[i]=(prpr(b[i-1],K)+a[i])%M;return;}
    inline int Hash_num(int *a,int L){int ans=0;for(int i=1;i<=L;i++)ans=(prpr(ans,K)+a[i])%M;return ans;}
}MA,MB,MC,MD;
namespace fac
{
    const int M=998244353;
    inline int prpr(int x,int y){return 1LL*x*y%M;}
    inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}
    int sl[N];
    int sr[N];
    inline void init()
    {
        sl[0]=sr[0]=1;
        for(int i=1;i<N;i++)sl[i]=prpr(sl[i-1],i);
        sr[N-1]=ksm(sl[N-1],M-2);for(int i=N-2;i;i--)sr[i]=prpr(sr[i+1],i+1);
        return;
    }
}
inline void Hash_init(){MA.init(25384013,31);MB.init(16360361,37);MC.init(19260817,41);MD.init(19437413,43);return;}

int a[N];
int b[N];
LL c[N];
inline void work()
{
    int A,B,n;
    A=rin();B=rin();n=rin();
    for(int i=1;i<=n;i++)a[i]=rin();
    int i;
    int maxl=-1,st=0;
    for(i=1;i<=n;i++)
    {
        b[i]=rin();
        int rs=(b[i]-1)/A+1;
        c[i]=1LL*rs*a[i];
        if(a[i]>maxl)maxl=a[i],st=i;
    }
    for(int i=1;i<=n;i++)if(st!=i)B-=c[i];
    // printf("B:%d\n",B);
    if(B<=0)puts("NO");
    else
    {
        puts(B>c[st]-a[st]?"YES":"NO");
    }
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}