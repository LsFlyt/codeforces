#include<cstdio>
#include<cstring>
#include<iostream>

#define MAXN 100000

using namespace std;

struct segment_tree
{
	int l,r;
	pair<double,double> data;
};

segment_tree t[5*MAXN+50];
int n,m;
pair<double,double> f[MAXN+50];

pair<double,double> merge(pair<double,double> x,pair<double,double> y)
{
	double l1=x.first;
	double r1=x.second;
	double l2=y.first;
	double r2=y.second;
	double l=(l1*l2)/(1-(1-l2)*r1);
	double r=r2+((1-r2)*r1*l2)/(1-(1-l2)*r1);
	return {l,r};
}

void update(int p)
{
	t[p].data=merge(t[p<<1].data,t[(p<<1)+1].data);
}

void build(int p,int l,int r)
{
	t[p].l=l;t[p].r=r;
	if (l==r)
	{
		t[p].data={f[l].first/f[l].second,f[l].first/f[l].second};
		return;
	}
	int mid=(l+r) >> 1;
	build(p<<1,l,mid);
	build((p<<1)+1,mid+1,r);
	update(p);
}

pair<double,double> get(int p,int l,int r)
{
	if (t[p].l==l && t[p].r==r)
	{
		return t[p].data;
	}
	int mid=(t[p].l+t[p].r) >> 1;
	if (r<=mid) return get(p<<1,l,r);
	if (l>mid) return get((p<<1)+1,l,r);
	return merge(get(p<<1,l,mid),get((p<<1)+1,mid+1,r));
}

void change(int p,int l,double c)
{
	if (t[p].l==t[p].r)
	{
		t[p].data={c,c};
		return;
	}
	int mid=(t[p].l+t[p].r) >> 1;
	if (l<=mid)
	{
		change(p<<1,l,c);
	}
	else
	{
		change((p<<1)+1,l,c);
	}
	update(p);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&f[i].first,&f[i].second);
	}
	build(1,1,n);
	int op;
	int x,L,R;
	double l,r;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%lf%lf",&x,&l,&r);
			change(1,x,l/r);
		}
		else
		{
			scanf("%d%d",&L,&R);
			pair<double,double> ans=get(1,L,R);
			printf("%0.10f\n",ans.first);
		}
	}
	
	return 0;
}
