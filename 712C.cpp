#include<cstdio> 
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int a=y,b=y,c=y;
	int ans=0;
	while (a<x || b<x || c<x)
	{
		if (a>b)
		{
			swap(a,b);
		}
		if (a>c)
		{
			swap(a,c);
		}
		a=min(x,b+c-1);
		ans++;
	}
	
	printf("%d\n",ans);
		
	return 0;
}
