#include<iostream>
#define MAX 10
#include<climits>
using namespace std;
typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void input(int ne,edge e[]){
    for(int i=0;i<ne;i++)
    {
        cout<<"\nEnter source vertex for edge"<<" "<<i+1<<":";
        cin>>e[i].src;
        cout<<"\nEnter destination vertex for edge"<<" "<<i+1<<":";
        cin>>e[i].dest;
        cout<<"\nEnter weight for edge"<<" "<<i+1<<":";
        cin>>e[i].wt;
    }
}


void bellman_ford(int nv,edge e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];


  for(i=0;i<nv;i++)
  {
    dis[i]=INT_MAX;
  }


  dis[src_graph]=0;

  /* relaxing all the edges nv - 1 times */
  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      weight=e[j].wt;

      if(dis[u]!=INT_MAX && dis[u]+weight < dis[v])
      {
        dis[v]=dis[u]+weight;
      }
    }

  }

  /* checking if negative cycle is present */
  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;

    if(dis[u]+weight < dis[v])
    {
      cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
      return;
    }
  }

  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<=nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i];
  }
}
int main()
{
  int nv,ne,src_graph;
  edge e[MAX];

  cout<<"Enter the number of vertices: ";
  cin>>nv;


  printf("Enter the source vertex of the graph: ");
  cin>>src_graph;

  cout<<"\nEnter no. of edges: ";
  cin>>ne;

  input(ne,e);

  bellman_ford(nv,e,src_graph,ne);

  return 0;
}
