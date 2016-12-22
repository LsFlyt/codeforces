#include<cstdio> 
#include<iostream>
#include<cstring>

using namespace std;

int n;

int ask(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	int s;
	cin >> s;
	return s;
}

void get(int& x1,int& y1,int& x2,int& y2)
{
	int l,r;
	int ans,mid;
	l=x1;r=x2;
	ans=x1;
	while (l<=r)
	{
		mid=(l+r) >> 1;
		if (ask(x1,y1,mid,y2)==1)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	x2=ans;

	l=x1;r=x2;
	ans=x1;
	while (l<=r)
	{
		mid=(l+r) >> 1;
		if (ask(mid,y1,x2,y2)==0)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
			ans=mid;
		}
	}
	x1=ans;
	
	l=y1;r=y2;
	ans=y1;
	while (l<=r)
	{
		mid=(l+r) >> 1;
		if (ask(x1,y1,x2,mid)==1)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	y2=ans;
	
	l=y1;r=y2;
	ans=y1;
	while (l<=r)
	{
		mid=(l+r) >> 1;
		if (ask(x1,mid,x2,y2)==0)
		{
			r=mid-1;			
		}
		else
		{
			l=mid+1;
			ans=mid;
		}
	}
	y1=ans;	
}

int main()
{
	cin >> n;
	int l,r;
	int mid;
	int ans; 
	l=1;r=n;
	ans=1;
	while (l<=r)
	{
		mid=(l+r) >> 1;
		if (ask(1,1,n,mid)<1)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
			ans=mid;
		}
	}
	if (ask(1,1,n,ans)==1 && ask(1,ans+1,n,n)==1)
	{
		
		int x1,y1,x2,y2,x3,y3,x4,y4;
		x1=1;y1=1;x2=n;y2=ans;
		get(x1,y1,x2,y2);
		x3=1;y3=ans+1;x4=n;y4=n;
		get(x3,y3,x4,y4);
		printf("! %d %d %d %d %d %d %d %d",x1,y1,x2,y2,x3,y3,x4,y4);
		return 0;
	}
	
	l=1;r=n;
	ans=1;
	while (l<=r)
	{
		mid=(l+r) >> 1;
		if (ask(1,1,mid,n)<1)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
			ans=mid;
		}
	}

	int x1,y1,x2,y2,x3,y3,x4,y4;
	x1=1;y1=1;x2=ans;y2=n;
	get(x1,y1,x2,y2);
	x3=ans+1;y3=1;x4=n;y4=n;
	get(x3,y3,x4,y4);
	printf("! %d %d %d %d %d %d %d %d",x1,y1,x2,y2,x3,y3,x4,y4);

	return 0;
}
