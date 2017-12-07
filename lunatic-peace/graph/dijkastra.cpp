// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <stdio.h>
#include <limits.h>
  
// Number of vertices in the graph
#define V 9
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min_idx, min = INT_MAX;

   for (int i = 0; i< V;i++) {
        if(sptSet[i] == false && dist[i] < min) {
                min_idx = i;
                min = dist[i]; 
        }
   }
   return min_idx;
}
  
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; i++)
                printf("%d \t\t %d\n", i, dist[i]);
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
        bool sptSet[V] = {false};
        int dist[V] = {0};

        for (int i = 0;i<V;i++) {
                sptSet[i] = false;
                dist[i] = INT_MAX;
        }

        dist[src] = 0; 
        
        for (int i = 0;i< V;i++) 
        {
                int u = minDistance(dist, sptSet);
                sptSet[u] = true;
                for (int v = 0; v < V; v++) {
                        if (!sptSet[v] && graph[u][v] &&  dist[u] != INT_MAX && 
                                                          dist[u] + graph[u][v] < dist[v] ) {
                                dist[v] = dist[u] + graph[u][v];
                        }
                }
        }
        printSolution(dist,V);
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
