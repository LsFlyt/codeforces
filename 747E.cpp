#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct edge
{
	int y,next;
};

struct node
{
	int x,d;
};

edge v[1000050];
int tot=0;
int head[1000050];
int tail[1000050];
int l[1000050],r[1000050];
bool fa[1000050];
int op;
int now;
int L;
int ans=0;
char s[1000050];

void add(int x,int y)
{
	tot++;
	v[tot].y=y;
	v[tot].next=0;
	if (head[x])
	{
		v[tail[x]].next=tot;
		tail[x]=tot;
	}
	else
	{
		head[x]=tail[x]=tot;
	}
}

int get(int d)
{
	ans=max(ans,d);
	now++;
	l[now]=op;
	for (int i=op;i<=L;i++)
	{
		if (s[i]==',')
		{
			r[now]=i-1;
			op=i+1;
			break;
		}
	}
	int sum=0;
	while (s[op]!=',')
	{
		sum*=10;
		sum+=s[op]-'0';
		op++;
	}
	op++;
	int nownum=now;
	int nnn;
	for (int i=1;i<=sum;i++)
	{
		nnn=get(d+1);
		fa[nnn]=1;
		add(nownum,nnn);
	}
	return nownum;
}

void Print()
{
	queue<node> q;
	node temp;
	temp.x=1;temp.d=1;
	q.push(temp);
	node now;
	int lastd=0;
	while (!q.empty())
	{
		now=q.front();q.pop();
		if (now.x!=1)
		{
			if (lastd)
			{
				if (now.d!=lastd)
				{
					printf("\n");
				}
				else
				{
					printf(" ");
				}
			}
			lastd=now.d;
			for (int i=l[now.x];i<=r[now.x];i++)
			{
				printf("%c",s[i]);
			}
		}
		for (int i=head[now.x];i;i=v[i].next)
		{
			temp.x=v[i].y;
			temp.d=now.d+1;
			q.push(temp);
		}
	}
}

int main()
{
	scanf(" %s",s);
	L=strlen(s);
	s[L]=',';L++;s[L]=0;
	now=1;
	op=0;
	while(op<L) get(1);
	for (int i=2;i<=now;i++)
	{
		if (fa[i]==0) add(1,i);
	}
	printf("%d\n",ans);
	Print();
	printf("\n");
	return 0;
}
