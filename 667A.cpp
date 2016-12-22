#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

#define eps 1e-8

const double pi=acos(-1.0);
double d,h,v,e;

int sgn(double x)
{
	if (x>eps) return 1;
	if (x<-eps) return -1;
	return 0;
}

int main()
{
	scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
	double s=pi*h*d*d/4.0;
	e*=pi*d*d/4;
	if (sgn(v-e)>0)
	{
		v-=e;
		printf("YES\n");
		printf("%0.10f\n",s/v);
	}
	else
	{
		printf("NO");
	}
	
	return 0;
}
