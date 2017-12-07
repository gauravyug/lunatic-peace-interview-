#include<iostream>
#include<string.h>
#include<math.h>
#define INF 999
using namespace std;
struct wormHole
{
	int startX;
	int startY;
	int endX;
	int endY;
	int cost;
};
int findMin(int* a,int size,bool* visited)
{
	int min=INF;
	int index=0;
	for(int i=0;i<size;i++)
	{
		if(!visited[i] && a[i]<min)
		{
			min=a[i];
			index=i;
		}
	}
	return index;
}
void printDist(int* d,int size)
{
	cout<<"DISTANCES : "<<endl;
	for(int i=0;i<size;i++)
	printf("%.2d ",i);
	cout<<endl;
	for(int i=0;i<size;i++)
	printf("%.2d ",d[i]);
	cout<<endl;
}
int main()
{
	//every odd index contains details of the previous co-ordinations, but flipped
	//because worm holes are bi-directional we need to calculate distances to both ends of the wormhole
	wormHole holes[] = {{0,1,0,5,5},
						{0,5,0,1,5},
						{1,2,2,5,4},
						{2,5,1,2,4},
						{3,1,4,1,3},
						{4,1,3,1,3},
						{3,3,5,1,2},
						{5,1,3,3,2},
						{3,1,7,4,1},
						{7,4,3,1,1}};
	int size = sizeof(holes)/sizeof(holes[0]);
	size=size+2;
	//0th index is start, size-1th index is dest
	//that's why size+2, so this includes starting point, both ends of all wormholes and the destination point
	//i have assumed that start is 0,0 and end is 7,5; this can be configured easily
	int dist[size];
	for(int i=0;i<size;i++)
	dist[i]=INF;
	//starting distance is 0
	dist[0]=0;
	//0:0 to 7:5(destination) distance is 12
	dist[size-1]=12;
	bool* visited = new bool[size];
	memset(visited,false,size);
	while(true)
	{
		//get minimum cost co-ordinate till now
		int cur = findMin(dist,size,visited);
		visited[cur]=true;
		//if minimum cost co-ordinate is size-1(destination) then we are done
		if(cur==size-1)
		break;
		for(int i=1;i<size-1;i++)
		{
			if(i!=cur)
			{
				if(cur==0)
				{
					//if we are at starting point then distances are simply x+y of wormhole
					dist[i]=holes[i-1].startX + holes[i-1].startY;
				} else {
					//if we are at some wormhole then calculate distances to all ends of the other wormholes and keep only if less that current distances
					if((abs(holes[i-1].startX-holes[cur-1].startX)+abs(holes[i-1].startY-holes[cur-1].startY))<dist[i])
					dist[i]=(abs(holes[i-1].startX-holes[cur-1].startX)+abs(holes[i-1].startY-holes[cur-1].startY));
				}
			}
		}
		if(cur!=0)
		{
			//this part of the code is for the other end of the current wormhole
			//because i have stored 2 points for each wormhole i'm just calculating for the other end of the wormhole
			if(cur&1)
			{
				if(dist[cur]<dist[cur+1]+holes[cur-1].cost)
				dist[cur+1]=dist[cur]+holes[cur-1].cost;
			} else {
				if(dist[cur]<dist[cur-1]+holes[cur-1].cost)
				dist[cur-1]=dist[cur]+holes[cur-1].cost;
			}
			//this is distance to destination from current co-ordinate
			if((dist[cur]+(abs(5-holes[cur-1].startX)+abs(7-holes[cur-1].startY)))<dist[size-1])
			dist[size-1]=(dist[cur]+(abs(5-holes[cur-1].startX)+abs(7-holes[cur-1].startY)));
		}
		//printDist(dist,size);
		//system("pause");
	}
	cout<<"minimum dist : "<<dist[size-1]<<endl;
	return 0;
}
