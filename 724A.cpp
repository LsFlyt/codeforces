#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

string a,b;
int A,B;

int get(string p)
{
	if (p=="monday") return 1;
	if (p=="tuesday") return 2;
	if (p=="wednesday") return 3;
	if (p=="thursday") return 4;
	if (p=="friday") return 5;
	if (p=="saturday") return 6;
	if (p=="sunday") return 0;
}

int main()
{
	cin >> a;
	cin >> b;
	A=get(a);
	B=get(b);
	int C=B-A;
	C=(C%7+7)%7;
	if (C==0 || C==2 || C==3)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}
