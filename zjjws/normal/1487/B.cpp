#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
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
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n,m,k;
inline void work()
{
    n=rin();k=rin();
    if(n&1)
    {
        k--;
        LL L=n-1>>1;k%=(L*n);
        int ans=1+((k/n)<<1);
        int cutt=0;
        k%=n;
        if((k<<1)>(n-ans-1))cutt++;
        if((k<<1)>(n-ans-1+n-2))cutt++;
        // printf("cutt:%d\n",cutt);
        ans=(ans+cutt+k-1)%n+1;
        printf("%d\n",ans);
    }
    else printf("%d\n",(k-1)%n+1);
    
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 