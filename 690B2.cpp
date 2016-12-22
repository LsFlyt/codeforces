#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 500

struct point
{
	int x,y;
	point(){};
	point(int _x,int _y)
	{
		x=_x;y=_y;
	}
	friend point operator +(point a,point b)
	{
		return point(a.x+b.x,a.y+b.y);
	}
	friend point operator -(point a,point b)
	{
		return point(a.x-b.x,a.y-b.y);
	}
	friend int operator ^(point a,point b)
	{
		return a.x*b.y-a.y*b.x;
	}
	friend int operator *(point a,point b)
	{
		return a.x*b.x+a.y*b.y;
	}
};

int n;
int s[MAXN+5][MAXN+5];
char ch[MAXN+5];
int tot=0;
point p[(MAXN+5)*(MAXN+5)];
point stack[(MAXN+5)*(MAXN+5)];

int sqr(int x)
{
	return x*x;
}

int dist(point a,point b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}

bool cmp(const point &a,const point &b)
{
	if (((a-p[0])^(b-p[0]))>0) return 1;
	if (((a-p[0])^(b-p[0]))<0) return 0;
	return dist(a,p[0])<dist(b,p[0]);
}

int get_convex_hull(point p[],int n)
{
	int top=0;
	int now=0;
	for (int i=1;i<n;i++)
	{
		if (p[i].x<p[now].x || (p[i].x==p[now].x && p[i].y<p[now].y))
		{
			now=i;
		}
	}
	swap(p[0],p[now]);
	sort(p+1,p+n,cmp);
	stack[0]=p[0];
	stack[1]=p[1];
	top=2;
	for (int i=2;i<n;i++)
	{
		while (top>1 && ((p[i]-stack[top-2])^(stack[top-1]-stack[top-2]))>=0)
		{
			top--;
		}
		stack[top]=p[i];
		top++;
	}
	for (int i=1;i+i<top;i++)
	{
		swap(stack[i],stack[top-i]);
	}
	return top;
}

int main()
{
	//freopen("input.txt","r",stdin);
	while (1)
	{
		scanf("%d",&n);
		if (!n) break;
		memset(s,0,sizeof(s));
		for (int i=n;i;i--)
		{
			scanf(" %s",ch+1);
			for (int j=1;j<=n;j++)
			{
				s[i][j]=ch[j]-'0';
			}
		}
		tot=0;
		for (int i=1;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				if (s[i][j] && s[i+1][j] && s[i][j+1] && s[i+1][j+1])
				{
					p[tot]=point(j,i);
					tot++;
				}
			}
		}
		
		int m=get_convex_hull(p,tot);
		printf("%d\n",m);
		for (int i=0;i<m;i++)
		{
			printf("%d %d\n",stack[i].x,stack[i].y);
		} 
	}
	return 0;
}
