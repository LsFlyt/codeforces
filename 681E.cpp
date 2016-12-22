#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define MAXN 100000
#define eps 1e-10

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y)
	{
		x=_x;y=_y;
	}
	friend point operator + (point a,point b)
	{
		return point(a.x+b.x,a.y+b.y);
	}
	friend point operator - (point a,point b)
	{
		return point(a.x-b.x,a.y-b.y);
	}
	friend double operator ^ (point a,point b)
	{
		return a.x*b.y-a.y*b.x;
	}
	friend double operator * (point a,point b)
	{
		return a.x*b.x+a.y*b.y;
	}
	friend point operator * (point a,double b)
	{
		return point(a.x*b,a.y*b);
	}
	friend point operator * (double a,point b)
	{
		return point(a*b.x,a*b.y);
	}
};

struct circle
{
	point o;
	double r;
	circle(){}
	circle(point _o,double _r)
	{
		o=_o;r=_r;
	}
};

int sgn(double x)
{
	if (x>eps) return 1;
	if (x<-eps) return -1;
	return 0;
}

struct region
{
	double l,r;
	region(){}
	region(double _l,double _r)
	{
		l=_l;r=_r;
	}
	friend bool operator <(const region &a,const region &b)
	{
		if (sgn(a.l-b.l))
		{
			return sgn(a.l-b.l)<0;
		}
		return sgn(a.r-b.r)<0;
	}
};

const double pi=acos(-1.0);
circle c[MAXN+50];
region s[3*MAXN+50];
int n;

double ABS(double x)
{
	return x*sgn(x);
}

double sqr(double x)
{
	return x*x;
}

double dist(point a)
{
	return sqrt(sqr(a.x)+sqr(a.y));
}

int circle_cross_circle(circle a,circle b,region t[])
{
	double r1=a.r;
	double r2=b.r;
	double alpha=atan2(b.o.y-a.o.y,b.o.x-a.o.x);
	double l=dist(b.o-a.o);
	if (sgn(l-r1-r2)>=0)
	{
		return 0;
	}
	if (sgn(sqr(r2)-sqr(b.o.y-a.o.y)-sqr(b.o.x-a.o.x))>=0)
	{
		t[0]=region(-pi,pi);
		return 1;
	}
	double d1,d2;
	double theta;
	if (sgn(sqr(b.o.y-a.o.y)+sqr(b.o.x-a.o.x)-sqr(r1)-sqr(r2))>=0)
	{
		theta=acos((sqr(r1)+sqr(b.o.y-a.o.y)+sqr(b.o.x-a.o.x)-sqr(r2))/(2*r1*l));
	}
	else
	{
		theta=asin(r2/l);
	}
	d1=alpha-theta;
	d2=alpha+theta;
	if (sgn(d1-(-pi))<0)
	{
		t[0]=region(-pi,d2);
		t[1]=region(d1+2*pi,pi);
		return 2;
	}
	if (sgn(d2-pi)>0)
	{
		t[0]=region(-pi,d2-2*pi);
		t[1]=region(d1,pi);
		return 2;
		
	}
	t[0]=region(d1,d2);
	return 1;
}

int main()
{
	//freopen("input.txt","r",stdin);
	double x0,y0,v,T;
	scanf("%lf%lf%lf%lf",&x0,&y0,&v,&T);
	scanf("%d",&n);
	double x,y,r;
	c[0]=circle(point(x0,y0),v*T);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&x,&y,&r);
		c[i]=circle(point(x,y),r);
	}
	if (!sgn(c[0].r))
	{
		bool flag=0;
		for (int i=1;i<=n;i++)
		{
			if (sgn(c[i].r-dist(c[i].o-c[0].o))>=0)
			{
				printf("%0.10f\n",1.0);
				flag=1;
				break;
			}
		}
		if (!flag) printf("%0.10f\n",0);
	}
	else
	{
		int tot=0;
		int now;
		region t[3];
		for (int i=1;i<=n;i++)
		{
			now=circle_cross_circle(c[0],c[i],t);
			for (int i=0;i<now;i++)
			{
				tot++;
				s[tot]=t[i];
			}
		}
		sort(s+1,s+tot+1);
		double totl=s[1].r-s[1].l;
		double nowr=s[1].r;
		for (int i=2;i<=tot;i++)
		{
			if (sgn(nowr-s[i].r)>=0) continue;
			totl+=s[i].r-max(nowr,s[i].l);
			nowr=s[i].r;
		}
		printf("%0.10f\n",totl/(2*pi));
	}


	return 0;
}
