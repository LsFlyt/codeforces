#include<cstdio>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 2000

struct point
{
	long long x,y;
	point(){};
	point(long long _x,long long _y)
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
	friend bool operator <(point a,point b)
	{
		return a.x!=b.x?a.x<b.x:a.y<b.y;
	}
};

map<point,long long> s;
int tot=0;
int n;
long long ans=0;
point p[MAXN+50];
point t[MAXN*MAXN+50];

int main()
{
	}
	sort(p+1,p+n+1);
	s.clear();
	point now;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			now=p[j]-p[i];
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
			if (!s[now])
			{	
				t[tot]=now;
				tot++;
			}
			s[now]++;
		}
	}
	for (int i=0;i<tot;i++)
	{
		ans+=s[t[i]]*(s[t[i]]-1)/2;
	}
	//printf("%I64d\n",ans);
	ans>>=1;
	printf("%I64d\n",ans);
	
	
	return 0;
}
