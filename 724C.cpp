#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

long long MIN(long long a,long long b) {
	if (a==-1) return b;
	if (b==-1) return a;
	return min(a,b);
}

void ext_gcd(long long a,long long b,long long &x,long long &y) {
	if (!b) {
		x=1;
		y=0;
		return;
	}
	ext_gcd(b,a%b,y,x);
	y-=a/b*x;
}

long long ABS(long long x) {
	return x>=0?x:-x;
}

long long gcd(long long a,long long b) {
	if (!b) return a;
	return gcd(b,a%b);
}

long long get(long long a,long long b)
{
	if (a%b==0) return a/b;
	return a/b+1;
}

long long get(long long a,long long b,long long c1,long long c2) {
	long long c=c2-c1;
	if (c==0) {
		return c1;
	}
	if (c<0)
	{
		swap(a,b);
		swap(c1,c2);
		c*=-1;
	}
	b*=-1;
	long long x,y;
	long long d=gcd(ABS(a),ABS(b));
	if (c%d) return -1;
	c/=d;
	long long A=a/d;
	long long B=b/d;
	ext_gcd(A,B,x,y);
	if (A*x+B*y==-1)
	{
		x*=-1;y*=-1;
	}
	x*=c;y*=c;
	B*=-1;
	long long t=0;
	if (x<0) t=max(t,get(-x,B));
	if (y<0) t=max(t,get(-y,A));
	x+=B*t;y+=A*t;
	while (x<0 || y<0)
	{
		x+=B;y+=A;
	}
	t=min(x/B,y/A);
	x-=B*t;y-=A*t;
	while (x-B>=0 && y-A>=0)
	{
		x-=B;y-=A;
	}
	return a*x+c1;
}

long long n,m;
int k;
long long x,y;
long long now;
long long ans;

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%I64d%I64d%d",&n,&m,&k);
	for (int i=1; i<=k; i++) {
		scanf("%I64d%I64d",&x,&y);
		ans=get(2*n,2*m,x,y);
		now=get(2*n,2*m,2*n-x,2*m-y);
		ans=MIN(ans,now);
		now=get(2*n,2*m,2*n-x,y);
		ans=MIN(ans,now);
		now=get(2*n,2*m,x,2*m-y);
		ans=MIN(ans,now);
		printf("%I64d\n",ans);
	}
	return 0;
}
