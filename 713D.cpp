#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int f[1050][1050];
int d[1050][1050][10][10];
int s[1050][1050]; 
int n,m;

int RMQ(int x1,int y1,int x2,int y2)
{
	int k1=0,k2=0;
	while ((1<<(k1+1))<=x2-x1+1) k1++;
	while ((1<<(k2+1))<=y2-y1+1) k2++;
	x2=x2-(1<<k1)+1;
	y2=y2-(1<<k2)+1;
	return max(max(d[x1][y1][k1][k2],d[x2][y2][k1][k2]),max(d[x1][y2][k1][k2],d[x2][y1][k1][k2]));
}

int main()
{
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&s[i][j]);
			if (s[i][j])
			{
				f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
			}
			else
			{
				f[i][j]=0;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			d[i][j][0][0]=f[i][j];
		}
	}
	for (int k=0;(1<<k)<=n;k++)
	{
		for (int l=0;(1<<l)<=m;l++)
		{
			if (k+l==0) continue;
			for (int i=1;i+(1<<k)-1<=n;i++)
			{
				for (int j=1;j+(1<<l)-1<=m;j++)
				{
					if (k)
					{
						d[i][j][k][l]=max(d[i][j][k-1][l],d[i+(1<<(k-1))][j][k-1][l]);
					}
					else
					{
						d[i][j][k][l]=max(d[i][j][k][l-1],d[i][j+(1<<(l-1))][k][l-1]);
					}
				}
			}
		}
	}
	
	int T;
	int l,r,mid;
	int ans;
	int x1,y1,x2,y2;
	int now;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		l=1;r=min(x2-x1,y2-y1)+1;
		ans=0;
		while (l<=r)
		{
			mid=(l+r) >> 1;
			now=RMQ(x1+mid-1,y1+mid-1,x2,y2);
			if (now>=mid)
			{
				l=mid+1;
				ans=mid;
			}	
			else
			{
				r=mid-1;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
