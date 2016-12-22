#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int a,b,n,ansa,ansb;

int main()
{
	scanf("%d",&n);
	ansa=1;ansb=n;
	for (int i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			a=min(i,n/i);
			b=max(i,n/i);
			if (b-a<ansb-ansa)
			{
				ansa=a;
				ansb=b;
			}
		}
	}
	printf("%d %d\n",ansa,ansb);
	
	return 0;
}
