#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int s[100050];
int tot=0;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+1,s+n+1);
	tot=unique(s+1,s+n+1)-s-1;
	if (tot==3)
	{
		if (s[2]-s[1]==s[3]-s[2])
		{
			printf("YES\n");
			return 0;
		}
	}
	if (tot==2 || tot==1)
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}
