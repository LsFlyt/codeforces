#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n;
int c[200050];
int d[200050];

int main()
{
	scanf("%d",&n);
	int L=-0x7fffffff,R=0x7fffffff;
	c[0]=0;
	bool flag=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
		c[i]+=c[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		if (d[i]==1)
		{
			L=max(L,1900-c[i-1]);
		}
		else
		{
			R=min(R,1899-c[i-1]);
			flag=1;
		}
	}
	if (L>R)
	{
		printf("Impossible\n");
	}
	else
	{
		if (!flag)
		{
			printf("Infinity\n");
		}
		else
		{
			printf("%d\n",R+c[n]);
		}
	}
	
	return 0;
}
