#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define MAXN 200000

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

int top=0;
point p[MAXN+50];
int n;
long long sum[MAXN+50];
long long mul[MAXN+50];
long long s[MAXN+50];
long long ans=0;

void ins(point x)
{
	while (top>1 && ((p[top-1]-p[top-2])^(x-p[top-2]))>=0)
	{
		top--;
	}
	p[top]=x;
	top++;
}

long long get(point x)
{
	int L=0,R=top-1;
	int mid1,mid2;
	while (R-L>=3)
	{
		mid1=(L*2+R)/3;
		mid2=(L+R*2)/3;
		if ((x*p[mid1])<(x*p[mid2]))
		{
			L=mid1;
		}
		else
		{
			R=mid2;
		}
	}
	long long temp=p[L]*x;
	for (int i=L+1;i<=R;i++)
	{
		temp=max(temp,p[i]*x);
	}
	return temp;
}

int main()
{
	scanf("%d",&n);
	memset(s,0,sizeof(s));
	memset(sum,0,sizeof(sum));
	memset(mul,0,sizeof(mul));
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&s[i]);
		sum[i]=sum[i-1]+s[i];
		mul[i]=mul[i-1]+s[i]*i;
	}
	ins(point(0,0));
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,mul[i]+get(point(-sum[i],1)));
		ins(point(i,i*sum[i]-mul[i]));
		//printf("x=%I64d y=%I64d\n",i,i*sum[i]-mul[i]);
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}
