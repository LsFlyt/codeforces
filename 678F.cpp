#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MAXN 300000
#define INF (long long)99999999999999999999

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
	friend bool operator <(point a,point b)
	{
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
};

struct segment_tree
{
	int l,r;
	vector<point> s;
};

point s[MAXN+50];
point stack[MAXN+50];
int top;
int l[MAXN+50],r[MAXN+50];
int op[MAXN+50];
segment_tree t[5*MAXN+50];
long long ans[MAXN+50];
int flag_empty[MAXN+50];
int n;

void build(int p,int l,int r)
{
	t[p].l=l;
	t[p].r=r;
	t[p].s.clear();
	if (l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}

void add(int p,int l,int r,int x)
{
	if (t[p].l==l && t[p].r==r)
	{
		t[p].s.push_back(s[x]);
		return;
	}
	int mid=(t[p].l+t[p].r)>>1;
	if (r<=mid)
	{
		add(p<<1,l,r,x);
		return;
	}
	if (l>mid)
	{
		add(p<<1|1,l,r,x);
		return;
	}
	add(p<<1,l,mid,x);
	add(p<<1|1,mid+1,r,x);
}

void ask(int x)
{
	int L=1,R=top;
	int mid1,mid2;
	while (L+3<=R)
	{
		mid1=(L*2+R)/3;
		mid2=(L+R*2)/3;
		if ((s[x]*stack[mid1])<(s[x]*stack[mid2]))
		{
			L=mid1;
		}
		else
		{
			R=mid2;
		}
	}
	for (int i=L;i<=R;i++)
	{
		ans[x]=max(ans[x],stack[i]*s[x]);
	}
}

void get(int p)
{
	if (t[p].l!=t[p].r)
	{
		get(p<<1);
		get(p<<1|1);
	}
	sort(t[p].s.begin(),t[p].s.end());
	top=0;
	int nown=t[p].s.size();
	for (int i=0;i<nown;i++)
	{
		while (top>1 && ((stack[top]-stack[top-1])^(t[p].s[i]-stack[top]))>=0) top--;
		top++;
		stack[top]=t[p].s[i];
	}
	for (int i=t[p].l;i<=t[p].r;i++)
	{
		if (op[i]==3 && flag_empty[i]) ask(i);
	}
}

int main()
{
	scanf("%d",&n);
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	int now=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&op[i]);
		if (op[i]==1)
		{
			scanf("%I64d%I64d",&s[i].x,&s[i].y);
			l[i]=i;
			r[i]=n;
			now++;
		}
		else
		{
			scanf("%I64d",&s[i].x);
			s[i].y=1;
		}
		if (op[i]==2)
		{
			r[s[i].x]=i;
			now--;
		}
		flag_empty[i]=now;
		ans[i]=-INF;
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		if (op[i]==1)
		{
			add(1,l[i],r[i],i);
		}
	}
	get(1);
	
	for (int i=1;i<=n;i++)
	{
		if (op[i]!=3) continue;
		if (flag_empty[i])
		{
			printf("%I64d\n",ans[i]);
		}
		else
		{
			printf("EMPTY SET\n");
		}
	}
	
	return 0;
}
