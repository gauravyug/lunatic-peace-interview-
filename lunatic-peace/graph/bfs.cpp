// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices 
// reachable from s.
#include<iostream>
#include <list>
#include <queue>
 
using namespace std;

class Graph{
        
        int V;
        
        // Pointer to an array containing adjacency
        // lists
        list <int> *adjList;

        public:
                Graph(int V);
                void addEdge(int v, int wt);
                void BFS(int src);

};

Graph::Graph(int V)
{
        this->V = V;
        adjList = new list<int>[V]; 
}

void Graph::addEdge(int v, int wt)
{
        adjList[v].push_back(wt);
}

void Graph::BFS(int src)
{
        bool visited[V] = {false};
        for (int i = 0; i<V; i++)
                visited[i] = false;
        
        queue<int> q;
        visited[src] = true;
        q.push(src);

        list<int>::iterator itr;

        while (!q.empty()) {
                src  = q.front();
                cout << src << " ";
                q.pop();
                for (itr = adjList[src].begin(); itr != adjList[src].end(); ++itr ) {
                        if (!visited[*itr])
                        {
                                visited[*itr] = true;
                                q.push(*itr);
                        } 

                }
        }

        cout <<"\n";
}

int main()
{
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
        g.BFS(2);
       return 0;
}
