#include<stdio.h>
int n,a[3];
int main()
{
	scanf("%d",&n);
	a[0]=a[1]=n/3;
	a[2]=n-a[0]-a[1];
	if(a[0]%3==0)
	{
		if(a[2]%3==0)
		{
			a[0]--;
			a[1]--;
			a[2]+=2;
		}
		else
		{
			a[0]-=2;
			a[1]-=1;
			a[2]+=3;
		}
	}
	if(a[2]%3==0)
	{
		if(a[0]%3==1)
		{
			a[0]++;
			a[1]++;
			a[2]-=2;
		}
		else
		{
			a[0]--;
			a[1]--;
			a[2]+=2;
		}
	}
	printf("%d %d %d",a[0],a[1],a[2]);
}