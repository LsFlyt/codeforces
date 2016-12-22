#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

struct edge
{
	int x,y,next;
	long long l;
};

struct Node
{
	int x,y;
};

struct cmp
{
	bool operator()(Node a,Node b)
	{
		return a.y>b.y;
	}
};

const long long inf=1000000005;
int n,m,s,t;
long long L;
int id[10050];
long long dist[1050];
bool f[1050];
int vtot;
int tot=1;
int head[1050];
edge v[30050];

int add(int x,int y,long long l)
{
	tot++;
	v[tot].x=x;
	v[tot].y=y;
	v[tot].l=l;
	v[tot].next=head[x];
	head[x]=tot;
	return tot;
}

long long dij()
{
	for (int i=0;i<n;i++)
	{
		dist[i]=inf;
	}
	memset(f,0,sizeof(f));
	priority_queue<Node,vector<Node>,cmp> q;
	Node now;
	now.x=s;
	now.y=0;
	dist[s]=0;
	q.push(now);
	while (!q.empty())
	{
		now=q.top();
		q.pop();
		if (f[now.x]) continue;
		f[now.x]=1;
		for (int i=head[now.x];i;i=v[i].next)
		{
			if (dist[v[i].y]>dist[now.x]+v[i].l)
			{
				dist[v[i].y]=dist[now.x]+v[i].l;
				Node next;
				next.x=v[i].y;
				next.y=dist[v[i].y];
				q.push(next);
			}
		}
	}
	return dist[t];
}

long long judge(long long sum)
{
	for (int i=1;i<=vtot;i++)
	{
		v[id[i]].l=v[id[i]^1].l=1+min(sum,inf);
		sum-=v[id[i]].l-1;
	}
	
	return dij();	
}

int main()
{
	scanf("%d%d%I64d%d%d",&n,&m,&L,&s,&t);
	int vv,uu,ww;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&vv,&uu,&ww);
		if (!ww)
		{
			vtot++;
			id[vtot]=add(vv,uu,inf);
			add(uu,vv,inf);
		}
		else
		{
			add(vv,uu,ww);
			add(uu,vv,ww);
		}
	}
	if (dij()<L)
	{
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<=vtot;i++)
	{
		v[id[i]].l=1;
		v[id[i]^1].l=1;
	}
	if (dij()>L)
	{
		printf("NO\n");
		return 0;
	}
	long long l=0,r=vtot*inf;
	long long mid=0;
	while (l<=r) 
	{
		mid=(l+r) >> 1;
		long long temp=judge(mid);
		if (temp==L)
		{
			break;
		}
		if (temp<L)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	
	printf("YES\n");
	for (int i=2;i<=tot;i+=2)
	{
		printf("%d %d %I64d\n",v[i].x,v[i].y,v[i].l);
	}
	
	return 0;
}
