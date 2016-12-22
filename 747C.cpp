#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int t,k,d;
int s[105];
int sum,tot;

int main()
{
	scanf("%d%d",&n,&m);
	memset(s,0,sizeof(s));
	while (m--)
	{
		scanf("%d%d%d",&t,&k,&d);
		d=t+d-1;
		tot=0;
		for (int i=1;i<=n;i++)		
		{
			if (s[i]<t)
			{
				tot++;
			}
			if (tot==k) break;
		}
		if (tot==k)
		{
			tot=0;
			sum=0;
			for (int i=1;i<=n;i++)
			{
				if (s[i]<t)
				{
					sum+=i;
					tot++;
					s[i]=d;
				}
				if (tot==k) break;
			}
			printf("%d\n",sum);
		}
		else
		{
			printf("%d\n",-1);
		}
	}
	return 0;
}
