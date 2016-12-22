#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define MAXN 1000

struct point
{
	int x,y;
	point(){}
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
};

point p[MAXN+50];
int n;
int ans=0;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	p[n]=p[0];
	for (int i=1;i<n;i++)
	{
		if (((p[i]-p[i-1])^(p[i+1]-p[i]))>0)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	
	return 0;
} 
