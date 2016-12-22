#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct edge
{
	int x,y,l;
	int next;
};

edge v[200050];
int head[100050];
int n;
long long M;
int tot=0;

void add(int x,int y,int l)
{
	tot++;
	v[tot].x=x;v[tot].y=y;v[tot].l=l;
	v[tot].next=head[x];head[x]=tot;
}

void ext_gcd(long long a,long long b,long long &x,long long &y)
{
	if (!b)
	{
		x=1;y=0;return;
	}
	ext_gcd(b,a%b,y,x);
	y-=a/b*x;
}

void dfs()

int main()
{
	scanf("%d%I64d",&n,&M);
	int x,y,l;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		add(x,y,l);
		add(y,x,l);
	}
	
	dfs(1,0);
	
	return 0;
}
