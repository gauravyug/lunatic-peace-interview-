#include<bits/stdc++.h>
using namespace std;
int bin [8][8]  = {
                                {0,0,1,0,0,1,0,0},
                                {0,0,1,0,1,1,1,1},
                                {0,0,1,0,1,0,0,1},
                                {0,0,1,1,1,0,0,0},
                                {0,1,0,0,1,1,1,1},
                                {0,1,0,0,1,1,1,1},
                                {0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0}
                   };

//int bin[21][21],
    int dist[21][21],n;
struct point{
	int x,y;
};
bool valid(int x,int y)
{
	return x>=0 && x<=8 && y>=0 && y<=8 && bin[x][y]==1;
}
int x[]={-1,0,0,1};
int y[]={0,-1,1,0};
void func(int u,int v)
{
	int i;
	for(i=0;i<4;i++)
	{
		int newx=u+x[i],newy=v+y[i];
		if(valid(newx,newy) && dist[newx][newy]>dist[u][v]+1)
		{
			dist[newx][newy]=dist[u][v]+1;
			func(newx,newy);
		}
	}
}
void init()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		dist[i][j]=500;
	}
}
int main()
{
	cout << "Input no of rare elements:\n";
        cin>>n;
	int i,j;
/*        bin [8][8]  = {
                                {0,0,1,0,0,1,0,0},
                                {0,0,1,0,1,1,1,1},
                                {0,0,1,0,1,0,0,1},
                                {0,0,1,1,1,0,0,0},
                                {0,1,0,0,1,1,1,1},
                                {0,1,0,0,1,1,1,1},
                                {0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0}
                   };*/
/*	cout << "Enter Elements of Matrix:\n";
	for(i =0;i<8;i++)
	{
	cout << "Enter Elements at "<< i << "row of Matrix:\n";
		for(j=0;j<8;j++)
		cin>>bin[i][j];
	}*/
	struct point p[n];
	cout << "Enter location of rare elements:\n"; 
	for(i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	int ans=INT_MAX;
	cout << "iIterare over all rare elements:\n"; 
	for(i=0;i<n;i++)
	{
		init();
                cout << "Iterating first element:\n";
		dist[p[i].x][p[i].y]=0;
		func(p[i].x,p[i].y);
		int dis=0;
/*		for(int idx=0;idx<8;i++)
		{
			for(j=0;j<8;j++)
			cout<<dist[idx][j]<<"\t ";
			cout<<endl;
		}*/
		for(j=0;j<n;j++)
		        dis=max(dis,dist[p[j].x][p[j].y]);
		ans=min(ans,dis);
                cout << "ith dist =:" << ans << "\n";
	}
	cout<<ans<<endl;
}
