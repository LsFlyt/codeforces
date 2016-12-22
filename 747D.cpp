#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int x,op;
	friend bool operator <(node a,node b)
	{
		return a.op==b.op?a.x<b.x:a.op>b.op;
	}
};
int n,k;
int s[200050];
int sum;
node d[200050];
int tot=0;
int m;
int l[200050];
int r[200050];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		s[i]=s[i]>=0?1:0;
		sum+=s[i];
	}
	sum=n-sum;
	if (sum>k)
	{
		printf("-1\n");
	}
	else
	{
		s[0]=1;
		s[n+1]=1;
		m=0;
		int ans=0;
		k-=sum;
		sum=0;
		for (int i=1;i<=n+1;i++)
		{
			if (s[i]==0 && s[i-1])
			{
				m++;
				l[m]=i;
			}
			if (s[i] && s[i-1]==0)
			{
				r[m]=i-1;
			}
			if (s[i]!=s[i-1] && i!=n+1)
			{
				ans++;
			}
		}
		if (m==0)
		{
			printf("0\n");
			return 0;
		}
		if (m==1)
		{
			if (k>=n-r[m])
			{
				printf("1\n");
				return 0;
			}
			else
			{
				printf("2\n");
				return 0;
			}
		}
		tot=0;
		for (int i=2;i<=m;i++)
		{
			tot++;
			d[tot].x=l[i]-r[i-1]-1;
			d[tot].op=1;
			d[tot-1].op++;
		}
		if (r[m]!=n)
		{
			tot++;
			d[tot].x=n-r[m];
			d[tot].op=1;
			d[tot-1].op++;
		}
		if (r[m]==n)
		{
			d[tot].op++;
		}
		if (tot-1>=2) sort(d+1,d+tot+1);
		for (int i=1;i<tot;i++)
		{
			if (k>=d[i].x)
			{
				k-=d[i].x;
				ans-=2;
			}
		}
		if (k>=d[tot].x)
		{
			ans-=d[tot].op;
		}
		printf("%d\n",ans);
	}
	return 0;
}
