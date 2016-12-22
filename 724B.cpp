#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

bool flag=0;
int n,m;
int a[25][25];
int s[25][25];

bool judge()
{
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		sum=0;
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]!=j)
			{
				sum++;
			}
		}
		if (sum>2) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&s[i][j]);
		}
	}
	memcpy(a,s,sizeof(a));
	if (judge()) 
	{
		printf("YES\n");
		return 0;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=i+1;j<=m;j++)
		{
			memcpy(a,s,sizeof(a));
			for (int k=1;k<=n;k++)
			{
				swap(a[k][i],a[k][j]);
			}
			if (judge())
			{
				flag=1;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	if (flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}
