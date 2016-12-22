#include<cstdio> 
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	int n,m;
	bool flag=0;
	char op;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf(" %c",&op);
			if (op=='C' || op=='M' || op=='Y')
			{
				flag=1;
			}
		}
	}
	
	if (flag)
	{
		printf("#Color\n");
	}
	else
	{
		printf("#Black&White\n");
	}
	
	return 0;
}
