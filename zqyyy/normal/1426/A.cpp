#include <cstdio>
#include <cctype>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
inline void work(){
	int n=read(),x=read();
	if(n<=2)return puts("1"),void();
	n-=3;printf("%d\n",n/x+2);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}