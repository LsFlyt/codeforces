#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define MAXN 1000

int rmax[MAXN+50];
int rmin[MAXN+50];
int cmax[MAXN+50];
int cmin[MAXN+50];
int rnum[MAXN+50];
int cnum[MAXN+50];
int n,m;
int ans=0;

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	memset(rnum,0,sizeof(rnum));
	memset(cnum,0,sizeof(cnum));
	memset(rmin,0x3f3f3f3f,sizeof(rmin));
	memset(cmin,0x3f3f3f3f,sizeof(cmin));
	int x;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			if (x)
			{
				rmax[i]=max(rmax[i],j);
				rmin[i]=min(rmin[i],j);
				cmax[j]=max(cmax[j],i);
				cmin[j]=min(cmin[j],i);
				rnum[i]++;
				cnum[j]++;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (rnum[i])
		{
			ans+=rmax[i]-rnum[i];
			ans+=m-rmin[i]+1-rnum[i];
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (cnum[i])
		{
			ans+=cmax[i]-cnum[i];
			ans+=n-cmin[i]+1-cnum[i];
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
