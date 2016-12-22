#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int n;
long long s[3050];
long long d[3050];
long long f[3050][3050];
long long ans=0;
int tot=0;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> s[i];
		s[i]-=i;
		d[i]=s[i];
	}
	sort(d+1,d+n+1);
	tot=unique(d+1,d+n+1)-d-1;

	long long now;
	for (int i=1;i<=n;i++)
	{
		now=(long long)1e19;
		for (int j=1;j<=tot;j++)
		{
			now=min(now,f[i-1][j]);
			f[i][j]=now+abs(s[i]-d[j]);
		}
	}
	ans=(long long)1e19;
	for (int i=1;i<=tot;i++)
	{
		ans=min(ans,f[n][i]);
	}
	
	cout << ans; 
	
	return 0;
}
