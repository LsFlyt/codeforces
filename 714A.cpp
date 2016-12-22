#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	long long l1,r1,l2,r2,k;
	long long l,r;
	long long ans=0;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	l=max(l1,l2);
	r=min(r1,r2);
	if (l<=r)
	{
		ans=r-l+1;
		if (l<=k && k<=r)
		{
			ans--;
		}
	};
	cout << ans << endl;
	
	return 0;
}
