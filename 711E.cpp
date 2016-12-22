#include<cstdio>
#include<cstring>
#include<iostream>

#define MOD 1000003LL	
#define inv 500002LL

using namespace std;

long long Pow(long long x,long long y)
{
	long long now=1;
	while (y)
	{
		if (y&1)
		{
			now*=x;
			now%=MOD;
		}
		x*=x;
		x%=MOD;
		y>>=1;
	}
	return now%MOD;
}

int main()
{
	long long n,k;
	cin >> n >> k;
	if (n<=60 && k>(1LL<<n))
	{
		printf("1 1\n");
	}
	else
	{		
		long long tot=0;
		long long now=2;
		k--;
		while (now<=k)
		{
			tot+=k/now;
			now<<=1;
		}
		long long p=1,q=1;
		long long a=Pow(2LL,n);
		for (long long i=1;i<=k;i++)
		{
			p*=(a-i);
			p%=MOD;
			if (!p)
			{
				break;
			}
		}
		p*=Pow(inv,tot);
		p%=MOD;
		q=Pow(Pow(2LL,n),k);
		q*=Pow(inv,tot);
		p=q-p;
		cout << (p%MOD+MOD)%MOD << " " << (q%MOD+MOD)%MOD << endl;
	}
	
	return 0;
}
