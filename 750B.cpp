#include<cstdio>
#include<cstring>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	bool flag=1;
	int now=0;
	int op;
	char s[10];
	while (n--)
	{
		scanf("%d",&op);
		scanf(" %s",s);
		if (s[0]=='E' || s[0]=='W')
		{
			if (now==0 || now==20000)
			{
				flag=0;
				break;
			}
			continue;
		}
		if (s[0]=='N' && now==0)
		{
			flag=0;
			break;
		}
		if (s[0]=='S' && now==20000)
		{
			flag=0;
			break;
		}
		if (s[0]=='S') now+=op;
		if (s[0]=='N') now-=op;
		if (now<0 || now>20000)
		{
			flag=0;
			break;
		}
	}
	if (flag==1 && now==0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}
