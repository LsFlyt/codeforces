#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int d[105];
int n;
char s[105][105];
char ch[105];
int k;
int ans1=0,ans2=0;

int main()
{
	scanf("%d%d",&n,&k);
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",s[i]);
		d[strlen(s[i])]++;
	}
	scanf(" %s",ch);
	int L=strlen(ch);
	for (int i=1;i<L;i++)
	{
		ans1+=d[i];
		ans2+=d[i];
	}
	ans2+=d[L]-1;
	ans1+=ans1/k*5+1;
	ans2+=ans2/k*5+1;
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}
