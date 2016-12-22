#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	long long n;
	long long a,b;
	long long x,y;
	cin >> n;
	if (n==1 || n==2)
	{
		printf("-1\n");
	}
	else
	{
		if (n&1)
		{
			a=n*n;b=1;	
		}
		else
		{
			if (n%4==0)
			{
				a=2*n;b=n/2;
			}
			else
			{
				for (long long i=2;i*i<=n;i++)
				{
					if (n%i==0)
					{
						if (i&1)
						{
							a=n*i;b=n/i;
							break;
						}
						if ((n/i)&1)
						{
							a=n*n/i;b=i;
							break;
						}
					}
				}
			}
		}
		x=(a+b)/2;
		y=(a-b)/2;
		if (x>y)
		{
			swap(x,y);
		}
		cout << x << " " << y << endl;
	}
	
	return 0;
}
