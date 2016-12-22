#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>

using namespace std;

struct edge
{
	int x,y,l,next;
};

struct point
{
	int s,num;
};

const int inf=1e9+50;
edge v[5050];
int head[5050];
int d[5050][5050];
int last[5050][5050];
bool f[5050][5050];
int n,m,T;
int tot=0;

void spfa()
{
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			d[i][j]=inf;
		}
	}
	memset(f,0,sizeof(f));
	queue<point> q;
	d[1][1]=0;
	point now;
	point next;
	now.s=1;now.num=1;
	q.push(now);
	while (!q.empty())
	{
		now=q.front();
		q.pop();
		f[now.s][now.num]=0;
		for (int x=head[now.s];x;x=v[x].next)
		{
			if (d[v[x].y][now.num+1]>d[now.s][now.num]+v[x].l)
			{
				d[v[x].y][now.num+1]=d[now.s][now.num]+v[x].l;
				last[v[x].y][now.num+1]=now.s;
				if (!f[v[x].y][now.num+1])
				{
					f[v[x].y][now.num+1]=1;
					next.s=v[x].y;
					next.num=now.num+1;
					q.push(next);
				}
			}
		}
	}
}

void add(int x,int y,int l)
{
	tot++;
	v[tot].x=x;v[tot].y=y;v[tot].l=l;
	v[tot].next=head[x];
	head[x]=tot;
}

void Print(int now,int d)
{
	if (now!=1)
	{
		Print(last[now][d],d-1);
	}
	printf("%d ",now);
}

int main()
{
	scanf("%d%d%d",&n,&m,&T);
	int x,y,l;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		add(x,y,l);
	}
	
	spfa();
	
	for (int i=n;i;i--)
	{
		if (d[n][i]<=T)
		{
			cout << i << endl;
			Print(n,i);
			break;
		}
	}
	
	return 0;
}
