#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int n;
int maxa=0;
int sum=0;
int s[105];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		sum+=s[i];
		maxa=max(s[i],maxa);
	}
	
	printf("%d\n",maxa*n-sum);	
	
	return 0;
}
