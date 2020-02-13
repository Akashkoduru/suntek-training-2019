/*0 1 4
0 2 5
2 3 3
1 3 -10
0--1    0
0--2    4
2--3    5
1--3    -6
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Edge
{
	int u,v,w,flag;
}Edge;
Edge e[20]; 
void bellman(int n,int m)
{
	int i,j,flag,dist[n];
	for(i=0;i<n;i++)
		dist[i]=INT_MAX;
	dist[0]=0;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<m;j++)
		{
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	//negative cycle detection
	flag=0;
	for(j=0;j<m;j++)
		{
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				flag=1;
			}
		}
	if(flag==1)
	printf("negative cycle detected");//
	for(i=0;i<n;i++)
	{
		printf("%d--%d\t%d\n",e[i].u,e[i].v,dist[i]);
	}
}
void main()
{
	int n,m,i;
	printf("enter the size :");
	scanf("%d",&n);
	printf("enter the no of edges :");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	bellman(n,m);
	
}
