#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,a[N];
inline void work(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=abs(read())*(i&1?1:-1);
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    puts("");
}
int main(){
    int T=read();
    while(T--)work();
    return 0;
}