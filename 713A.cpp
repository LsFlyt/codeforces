#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>

using namespace std;

map<long long,int> S[1<<19];
long long ans[1<<19];
int T;
char op;

int HASH(long long x)
{
	int now=0;
	int sum=0;
	while (x)
	{
		if (x&1)
		{
			sum+=1<<now;
		}
		now++;
		x/=10;
	}	
	return sum;
}

int main()
{
	cin >> T;
	long long x;
	int s;
	while (T--)
	{
		scanf(" %c",&op);
		cin >> x;
		s=HASH(x);
		switch (op)
		{
			case '+':
				{
					S[s][x]++;
					ans[s]++;			
					break;	
				}
			case '-':
				{
					if (S[s][x])
					{
						S[s][x]--;
						ans[s]--;
					}
					break;
				}
			case '?':
				{
					cout << ans[s] << endl;
					break;
				}
		}
	}
	
	return 0;
}
