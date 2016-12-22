#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct region
{
	int l,r;
};

region s[200050];
int tot;
int n,a,b,k;
int now;
int last;
char ch[200050];
int anstot=0;
int ans[200050];
int sum=0;

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf(" %s",ch+1);

	ch[0]='1';
	ch[n+1]='1';
	now=-1;
	for (int i=0;i<=n+1;i++)
	{
		if (ch[i]=='1')
		{
			if (now!=i-1)
			{
				tot++;
				s[tot].l=now+1;
				s[tot].r=i-1;
				sum+=(s[tot].r-s[tot].l+1)/b;
			}
			now=i;
		}
	}
	now=1;
	int l,r;
	while (sum>=a)
	{
		while ((s[now].r-s[now].l+1)/b<=0)
		{
			now++;
		}
		anstot++;
		ans[anstot]=s[now].r-b+1;
		s[now].r-=b;
		sum--;
		
	}
	
	printf("%d\n",anstot);
	for (int i=1;i<=anstot;i++)
	{
		printf("%d ",ans[i]);
	}
	
	return 0;
}
