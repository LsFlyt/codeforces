#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,c;
int now,last;
int ans=0;

int main()
{
	scanf("%d%d",&n,&c);
	scanf("%d",&now);
	ans=1;
	for (int i=2;i<=n;i++)
	{
		last=now;
		scanf("%d",&now);
		if (now-last>c) ans=0;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
