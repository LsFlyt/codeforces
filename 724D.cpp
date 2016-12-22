#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int m;
int L;
char s[100050];
char a[100050];

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&m);
	scanf(" %s",s);
	L=strlen(s);
	for (char x='a';x<='z';x++)
	{
		int now=-1;
		int last;
		bool flag;
		bool flag2=1;
		int tot=0;
		while (now+m<L)
		{
			flag=0;
			last=now;
			for (int i=last+1;i<=last+m;i++)
			{
				if (s[i]<x)
				{
					tot++;
					a[tot]=s[i];
					flag=1;
					now=i;
				}
			}
			if (!flag)
			{
				for (int i=last+m;i>=last+1;i--)
				{
					if (s[i]==x)
					{
						tot++;
						a[tot]=s[i];
						flag=1;	
						now=i;
						break;
					}
				}
			}
			if (!flag)
			{
				flag2=0;	
				break;
			}
		}
		if (flag2)
		{
			for (int i=now+1;i<L;i++)
			{
				if (s[i]<x)
				{
					tot++;
					a[tot]=s[i];
				}
			}
			sort(a+1,a+tot+1);
			a[tot+1]=0;
			printf("%s\n",a+1);
			break;
		}
	}
	return 0;
}
