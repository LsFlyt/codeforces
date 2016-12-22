#include<cstdio>
#include<cstring>

using namespace std;

const long long MOD=1e9+7;
const long long inv=5e8+4;

struct node
{
	long long a,b;
	node(){}
	node(long long _a,long long _b)
	{
		a=_a%MOD;b=_b%MOD;
	}
	friend node operator +(node x,node y)
	{
		return node(x.a+y.a,x.b+y.b);
	}
	friend node operator -(node x,node y)
	{
		return node(x.a-y.a,x.b-y.b);
	}
	friend node operator *(node x,node y)
	{
		return node(x.a*y.a+5*x.b*y.b,x.a*y.b+x.b*y.a);
	}
};

struct segment
{
	node data;
	node lazy;
	int l,r;
};

segment t1[500050],t2[500050];
int s[100050];
int n,m;

node Pow(node x,int y)
{
	node now;
	now.a=1;now.b=0;
	while (y)
	{
		if (y&1)
		{
			now=now*x;
		}
		x=x*x;
		y>>=1;
	}
	return now;
}

void update(segment t[],int p)
{
	t[p].data=t[p<<1].data+t[(p<<1)+1].data;
}

void spread(segment t[],int p)
{
	if (t[p].lazy.a==1 && t[p].lazy.b==0)
	{
		return;
	}
	t[p<<1].data=t[p<<1].data*t[p].lazy;
	t[p<<1].lazy=t[p<<1].lazy*t[p].lazy;
	t[(p<<1)+1].data=t[(p<<1)+1].data*t[p].lazy;
	t[(p<<1)+1].lazy=t[(p<<1)+1].lazy*t[p].lazy;
	t[p].lazy=node(1,0);
}

void build(segment t[],int p,int l,int r,node c)
{
	t[p].l=l;t[p].r=r;t[p].lazy=node(1,0);
	if (l==r)
	{
		t[p].data=Pow(c,s[l]);
		return;
	}
	int mid=(l+r) >> 1;
	build(t,p<<1,l,mid,c);
	build(t,(p<<1)+1,mid+1,r,c);
	update(t,p);
}

void change(segment t[],int p,int l,int r,node c)
{
	if (t[p].l==l && t[p].r==r)
	{
		t[p].lazy=t[p].lazy*c;
		t[p].data=t[p].data*c;
		return;
	}
	spread(t,p);
	int mid=(t[p].l+t[p].r) >> 1;
	if (r<=mid)
	{
		change(t,p<<1,l,r,c);
		update(t,p);
		return;
	}
	if (l>mid)
	{
		change(t,(p<<1)+1,l,r,c);
		update(t,p);
		return;
	}
	change(t,p<<1,l,mid,c);
	change(t,(p<<1)+1,mid+1,r,c);
	update(t,p);
}

node get(segment t[],int p,int l,int r)
{
	if (t[p].l==l && t[p].r==r)
	{
		return t[p].data;
	}
	spread(t,p);
	int mid=(t[p].l+t[p].r) >> 1;
	if (r<=mid)
	{
		return get(t,p<<1,l,r);
	}
	if (l>mid)
	{
		return get(t,(p<<1)+1,l,r);
	}
	return get(t,p<<1,l,mid)+get(t,(p<<1)+1,mid+1,r);
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	build(t1,1,1,n,node(inv,inv));
	build(t2,1,1,n,node(inv,-inv));
	int op,l,r,x;
	node now;
	node now1,now2;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			now=Pow(node(inv,inv),x);
			change(t1,1,l,r,now);
			now=Pow(node(inv,-inv),x);
			change(t2,1,l,r,now);
		}
		else
		{
			scanf("%d%d",&l,&r);
			now1=get(t1,1,l,r);
			now2=get(t2,1,l,r);
			now=now1-now2;
			printf("%I64d\n",(now.b%MOD+MOD)%MOD);
		}
	}
	return 0;
}
