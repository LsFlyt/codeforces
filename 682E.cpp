#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAXN 5000

struct point
{
	long long x,y;
	point(){}
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
	friend long long operator ^(point a,point b)
	{
		return a.x*b.y-a.y*b.x;
	}
	friend long long operator *(point a,point b)
	{
		return a.x*b.x+a.y*b.y;
	}
};

int n;
long long S;
point p[MAXN+50];
point stack[MAXN+50];

long long sqr(long long x)
{
	return x*x;
}

long long dist(point a,point b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}

bool cmp(const point &a,const point &b)
{
	if (((a-p[0])^(b-p[0]))>0) return 1;
	if (((a-p[0])^(b-p[0]))<0) return 0;
	return dist(a,p[0])<dist(b,p[0]);
}

long long ABS(long long x)
{
	return x>=0?x:-x;
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
	for (int i=0;i<top;i++)
	{
		p[i]=stack[i];
	}
	p[top]=p[0];
	return top;
}

void rotating_calipers(point p[],int n,point &a,point &b,point &c)
{
	a=p[0];b=p[1];c=p[2];
	for (int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		int k=(i+1)%n;
		while (i!=j && i!=k)
		{
			while (ABS((p[j]-p[i])^(p[k]-p[i]))<ABS((p[j]-p[i])^(p[(k+1)%n]-p[i]))) k=(k+1)%n;
			if (ABS((b-a)^(c-a))<ABS((p[j]-p[i])^(p[k]-p[i])))
			{
				a=p[i]; b=p[j]; c=p[k];
			}
			j=(j+1)%n;
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%I64d",&n,&S);
	for (int i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
	}
	int m=get_convex_hull(p,n);
	
	point a,b,c;
	rotating_calipers(p,n,a,b,c);
	
	point A=a+b-c;
	point B=b+c-a;
	point C=c+a-b;
	printf("%I64d %I64d\n",A.x,A.y);
	printf("%I64d %I64d\n",B.x,B.y);
	printf("%I64d %I64d\n",C.x,C.y);
	return 0;
}
