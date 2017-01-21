#include<cstdio>
#include<cstring>

using namespace std;

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	int tot=0;
	int i=1;
	k=240-k;
	while (tot+5*i<=k && i<=n)
	{
		tot+=5*i;
		i++;
	}
	i--;
	printf("%d\n",i);
	return 0;
}
