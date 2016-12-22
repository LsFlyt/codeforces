#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n;
int tot[4];
char s[300];
char c[5]="ACGT";

int main()
{
	scanf("%d",&n);
	scanf(" %s",s+1);
	for (int i=1;i<=n;i++)
	{
		switch (s[i])
		{
			case 'A':
				{
					tot[0]++;
					break;
				}
			case 'C':
				{
					tot[1]++;
					break;
				}
			case 'G':
				{
					tot[2]++;
					break;
				}
			case 'T':
				{
					tot[3]++;
					break;
				}
		}
	}
	
	if (n%4==0)
	{
		for (int i=0;i<4;i++)
		{
			if (tot[i]>n/4)
			{
				printf("===\n");
				return 0;
			}
			else
			{
				tot[i]=n/4-tot[i];
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (s[i]!='?')
			{
				printf("%c",s[i]);
			}
			else
			{
				int now=0;
				while (!tot[now] && now<4)
				{
					now++;
				}
				if (now==4)
				{
					for (int i=0;i<4;i++) tot[i]=1;
					now=0;
				}
				printf("%c",c[now]);
				tot[now]--;
			}
		}
	}
	else
	{
		printf("===\n");
	}
	
	return 0;
}
