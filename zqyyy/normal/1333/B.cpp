#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,a[N],b[N];
inline void work(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    bool hv1=0,hv_1=0,ok=1;
    for(int i=1;i<=n;i++){
	if(a[i]<b[i])ok&=hv1;
	if(a[i]>b[i])ok&=hv_1;
	hv1|=a[i]==1,hv_1|=a[i]==-1;
    }
    puts(ok?"YES":"NO");
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}