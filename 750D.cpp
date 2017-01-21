#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

struct node
{
	int x,y,nowd,nowt,nowc;
	node(){}
	node(int _x,int _y,int _nowd,int _nowt,int _nowc)
	{
		x=_x;y=_y;nowd=_nowd;nowt=_nowt;nowc=_nowc;
	}
};

const int dx[8]={0,-1,-1,-1,0,1,1,1};
const int dy[8]={1,1,0,-1,-1,-1,0,1};
int n;
int t[50];
int f[400][400];
int ans=1;
bool w[400][400][8][5][31];

void bfs()
{
	queue<node> q;
	node now=node(200,200,0,t[1]-1,1);
	w[200][200][0][t[1]-1][1]=1;
	f[200][200]=1;
	node next;
	q.push(now);
	while (!q.empty())
	{
		now=q.front();
		q.pop();
		if (now.nowt==0)
		{
			if (now.nowc==n) continue;
			next=now;
			next.nowd++;
			if (next.nowd==8) next.nowd=0;
			next.x+=dx[next.nowd];next.y+=dy[next.nowd];
			next.nowc++;
			next.nowt=t[next.nowc]-1;
			if (!w[next.x][next.y][next.nowd][next.nowt][next.nowc])
			{
				w[next.x][next.y][next.nowd][next.nowt][next.nowc]=1;
				if (!f[next.x][next.y])
				{
					ans++;
					f[next.x][next.y]=1;
				}
				q.push(next);
			}
			
			next=now;
			next.nowd--;
			if (next.nowd==-1) next.nowd=7;
			next.x+=dx[next.nowd];next.y+=dy[next.nowd];
			next.nowc++;
			next.nowt=t[next.nowc]-1;
			if (!w[next.x][next.y][next.nowd][next.nowt][next.nowc])
			{
				w[next.x][next.y][next.nowd][next.nowt][next.nowc]=1;
				if (!f[next.x][next.y])
				{
					ans++;
					f[next.x][next.y]=1;
				}
				q.push(next);
			}
		}
		else
		{
			next=now;
			next.x+=dx[next.nowd];next.y+=dy[next.nowd];
			next.nowt--;
			if (!w[next.x][next.y][next.nowd][next.nowt][next.nowc])
			{
				w[next.x][next.y][next.nowd][next.nowt][next.nowc]=1;
				if (!f[next.x][next.y])
				{
					ans++;
					f[next.x][next.y]=1;
				}
				q.push(next);
			}
		}	
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	bfs();
	printf("%d\n",ans);
	
	return 0;
}
