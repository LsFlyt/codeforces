#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
long long s,t;
long long g[200050];
long long c[200050];
long long v[200050];

bool check(long long V)
{
	long long tottime=0;
	long long now;
	long long L;
	for (int i=1;i<=k;i++)
	{
		L=g[i]-g[i-1];
		if (L>V)
		{
			return 0;
		}
		now=max((long long)0,2*L-V);
		tottime+=now+L;
		if (tottime>t)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	//freopen("input.txt","r",stdin);
	long long l=1;
	long long r=0;
	long long ans2;
	scanf("%d%d%I64d%I64d",&n,&k,&s,&t);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&c[i],&v[i]);
		r=max(r,v[i]);
		ans2=max(ans2,c[i]);
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%I64d",&g[i]);
	}
	sort(g+1,g+k+1);
	k++;
	g[k]=s;
	long long mid;
	long long ans=r+1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	bool flag=0;
	for (int i=1;i<=n;i++)
	{
		if (v[i]>=ans)
		{
			ans2=min(ans2,c[i]);
			flag=1;
		}
	}
	if (!flag)
	{
		printf("-1\n");
	}
	else
	{
		printf("%I64d\n",ans2);
	}
	
	return 0;
}
