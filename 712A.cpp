#include<cstdio>
#include<cstring>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	int now,last;
	scanf("%d",&last);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&now);
		printf("%d ",now+last);
		last=now;
	}
	printf("%d\n",last);
	
	return 0;
}
