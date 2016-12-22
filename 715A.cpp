#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",2);
	for (long long i=2;i<=n;i++)
	{
		printf("%I64d\n",i*i*i+i*i*2+1);
	}
	return 0;
}
