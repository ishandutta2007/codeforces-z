#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=110;
int n,p;
bool b[N]={};
int main()
{
	cin>>n>>p;
	for(int i=1,x=0;i<=p;++i)
	{
		cin>>x;
		b[x]=true;
	}
	cin>>p;
	for(int i=1,x=0;i<=p;++i)
	{
		cin>>x;
		b[x]=true;
	}
	for(int i=1;i<=n;++i)
		if(!b[i])
		{
			puts("Oh, my keyboard!");
			return 0;
		}
	puts("I become the guy.");
	return 0;
}