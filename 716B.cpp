#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

char s[50050];
bool flag=0;
bool d[26];
int L;

bool judge(int l,int r)
{
	memset(d,0,sizeof(d));
	int tot=0;
	int sum=0;
	for (int i=l;i<=r;i++)
	{
		if (s[i]=='?')
		{
			sum++;
			continue;
		}
		if (!d[s[i]-'A'])
		{
			d[s[i]-'A']=1;
			tot++;
		}
	}
	if (tot+sum>=26)
	{
		return 1;
	}
	return 0;
}

void make(int l,int r)
{
	for (int i=l;i<=r;i++)
	{
		if (s[i]=='?')
		{
			for (int j=0;j<26;j++)
			{
				if (!d[j])
				{
					s[i]='A'+j;
					d[j]=1;
					break;
				}
			}
		}
		if (s[i]=='?')
		{
			s[i]='A';
		}
	}
	for (int i=0;i<L;i++)
	{
		if (s[i]=='?')
		{
			s[i]='A';
		}
	}
}

int main()
{
	scanf(" %s",s);
	L=strlen(s);
	if (L<26)
	{
		printf("-1\n");
		return 0; 
	}
	for (int i=25;i<L;i++)
	{
		if (judge(i-25,i))
		{
			make(i-25,i);
			flag=1;
		}
	}
	
	if (flag)
	{
		printf("%s\n",s);
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
}
