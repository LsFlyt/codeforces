#include<cstdio> 
#include<cstring>
#include<iostream>

#define MAXN 100000

using namespace std;

int n,m,k;
bool f[MAXN+50];
int x[MAXN+50],y[MAXN+50],l[MAXN+50];
int ans=1000000001;

int main()
{
	
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&l[i]);
	}
	int s;
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&s);
		f[s]=1;
	}
	for (int i=1;i<=m;i++)
	{
		if (f[x[i]]^f[y[i]])
		{
			ans=min(ans,l[i]);
		}
	}
	
	if (ans==1000000001) ans=-1;
	printf("%d\n",ans);
	
	return 0;
}
