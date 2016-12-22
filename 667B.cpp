#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 100000

int n;
long long s[MAXN+50];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&s[i]);
	}
	sort(s+1,s+n+1);
	long long sum=0;
	for (int i=1;i<n;i++)
	{
		sum+=s[i];
	}
	if (s[n]<sum)
	{
		printf("%I64d\n",1);
	}
	else
	{
		printf("%I64d\n",s[n]-sum+1);
	}
	return 0;
}
