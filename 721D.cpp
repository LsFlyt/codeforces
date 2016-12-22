#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct Node
{
	long long x,y;
	int z;
};

int n,k;
long long x;
long long s[200050];
long long ans[200050];
int sum=0;

long long myabs(long long x)
{
	if (x>=0) return x;
	return -x;
}

struct cmp1
{
	bool operator()(Node a,Node b)
	{
		return myabs(a.x)>myabs(b.x);
	}
};

int main()
{
	scanf("%d%d%I64d",&n,&k,&x);
	Node now;
	priority_queue<Node,vector<Node>,cmp1> q;
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&s[i]);
		now.x=s[i];
		now.y=1;
		now.z=i;
		if (s[i]<0)
		{
			sum++;
			now.y=-1;
		}
		q.push(now);
	}

	if ((sum&1)==0)
	{
		while (k>0)
		{
			k--;
			now=q.top();
			q.pop();
			if ((now.x-now.y*x)*now.y<=0)
			{
				now.x=now.x-now.y*x;
				now.y*=-1;
				q.push(now);
				break;
			}
			else
			{
				now.x=now.x-now.y*x;
				q.push(now);
			}
		}
	}
	while (k>0)
	{
		k--;
		now=q.top();
		q.pop();
		now.x+=x*now.y; 
		q.push(now);
	}
	while (!q.empty())
	{
		now=q.top();
		q.pop();
		ans[now.z]=now.x;
	}
	for (int i=1;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}
