#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int L,n,p,t;
int l,r;
int f[100050];
int g[100050];
int head,tail;
int ans,ans1,ans2;

int main()
{
	scanf("%d%d%d%d",&L,&n,&p,&t);
	int now;
	head=tail=1;
	f[head]=0;
	g[head]=-t;
	ans=ans1=ans2=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		if (head>1)
		{
			head--;
		}
		while (g[head]+t<=r && head<=tail)
		{
			if (f[head]+(r-max(l,g[head]+t))/p>ans1)
			{
				ans1=f[head]+(r-max(l,g[head]+t))/p;
				ans2=max(l,g[head]+t)+(r-max(l,g[head]+t))/p*p;
			}
			else
			{
				if (f[head]+(r-max(l,g[head]+t))/p==ans1)
				{
					ans2=min(ans2,max(l,g[head]+t)+(r-max(l,g[head]+t))/p*p);
				}
			}
			head++;
		}
		if (ans1>ans)
		{
			ans=ans1;
			tail++;
			f[tail]=ans1;
			g[tail]=ans2;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
