#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[200050];

int main()
{
	//freopen("input.txt","r",stdin);
	int n,T;
	scanf("%d%d",&n,&T);
	scanf(" %s",s+1);
	int first=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='.')
		{
			first=i;
			break;
		}
	}
	if (!first || !T )
	{
		printf("%s\n",s+1);
		return 0;
	}
	int now=0;
	s[0]='0';
	for (int i=first+1;i<=n;i++)
	{
		if (s[i]>='5')
		{
			now=i;
			s[i]=0;
			break;
		}
	}
	int next=now-1;
	int last=now;
	if (s[next]=='.')
	{
		next--;
	}
	while (s[next]=='9')
	{
		s[next]='0';
		next--;
	}
	s[next]++;
	T--;
	while (T && now>first)
	{
		while (s[now]<'5' && now>first)
		{
			now--;
		}
		if (now==first) break;
		s[now]=0;
		next=now-1;
		if (s[next]=='.')
		{
			next--;
			while (s[next]=='9')
			{
				s[next]='0';
				next--;
			}
		}
		s[next]++;
		now--;
		T--;
	}
	int l=0;
	while (s[l]=='0')
	{
		l++;
	}
	if (s[l]=='.') l--;
	int L=strlen(s+l);
	if (l==0)
	{
		L--;
	}
	if (s[L]=='.')
	{
		s[L]=0;
	}
	if (strlen(s+l)==0)
	{
		printf("0\n");
	}
	else
	{
		printf("%s\n",s+l);
	}
	return 0;
}
