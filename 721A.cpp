#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

string s;
int n;
int tot=0;
int d[1050];

int main()
{
	cin >> n;
	cin >> s;
	s+='W';
	int now=0;
	for (int i=0;i<=n;i++)
	{
		if (s[i]=='W')
		{
			if (now)
			{
				tot++;
				d[tot]=now;
			}
			now=0;
		}
		else
		{
			now++;
		}
	}
	cout << tot << endl;
	for (int i=1;i<=tot;i++)
	{
		cout << d[i] << " ";
	}
	return 0;
}
