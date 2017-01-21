#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

char s[105];
int ans[5]={0,-1,-1,-1,-1};

int main()
{
	scanf("%s",s);
	int L=strlen(s);
	for (int i=0;i<L;i++)
	{
		if (s[i]=='R' && ans[1]==-1) ans[1]=L/4+(L%4>=i%4+1);
		if (s[i]=='B' && ans[2]==-1) ans[2]=L/4+(L%4>=i%4+1);
		if (s[i]=='Y' && ans[3]==-1) ans[3]=L/4+(L%4>=i%4+1);
		if (s[i]=='G' && ans[4]==-1) ans[4]=L/4+(L%4>=i%4+1);
	}
	
	for (int i=0;i<L;i++)
	{
		if (s[i]=='R') ans[1]--;
		if (s[i]=='B') ans[2]--;
		if (s[i]=='Y') ans[3]--;
		if (s[i]=='G') ans[4]--;
	}
	
	for (int i=1;i<=4;i++)
	{
		printf("%d%c",ans[i],i!=4?' ':'\n');
	}
	
	return 0;
}
