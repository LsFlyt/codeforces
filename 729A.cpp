#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

int n;
char s[105];
int f[105];
int num=0;

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf(" %s",s+1);
	int i=1;
	memset(f,0,sizeof(f));
	while (i<=n)
	{
		if (s[i]=='o' && s[i+1]=='g' && s[i+2]=='o')
		{
			num++;
			f[i]=num;
			for (int j=i+1;;j+=2)
			{
				if (s[j]=='g' && s[j+1]=='o')
				{
					f[j]=num;
					f[j+1]=num;
					continue;
				}
				i=j-1;
				break;
			}
		}
		i++;
	}
	int now;
	for (int i=1;i<=n;i++)
	{
		if (f[i])
		{
			printf("***");
			now=f[i];
			while (f[i]==now)
			{
				i++;
			}
			i--;
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	printf("\n");
	
	return 0;
}
