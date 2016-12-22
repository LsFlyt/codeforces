#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int L,R,U,D;
int ans=0;

int main()
{
	//freopen("input.txt","r",stdin);
	L=R=U=D=0;
	char op;
	while (~scanf(" %c",&op))
	{
		if (op=='L') L++;
		if (op=='R') R++;
		if (op=='U') U++;
		if (op=='D') D++;
	}
	
	if ((L+R+U+D)&1)
	{
		printf("%d\n",-1);
	}
	else
	{
		if (R>L)
		{
			swap(L,R);
		}
		L-=R;
		if (U>D)
		{
			swap(U,D);
		}
		D-=U;
		printf("%d\n",(L+D)/2);
	}
	
	return 0;
}
