#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std ;

class Graph
{
    int **matrix ;
    int V ;

    public :

    Graph(int V)
    {
        this->V = V ;

        matrix = new int*[V] ;
        for(int i = 0 ; i < V ; i++)
        {
            matrix[i] = new int[V];
            for(int j = 0; j < V ; j++)
                matrix[i][j] = 0 ;
        }
    }

    void addEdge(int u, int v, int cost)
    {
        matrix[u][v] = cost ;
        matrix[v][u] = cost ;
    }

    void display()
    {
        for(int i = 0 ; i < V ; i++)
        {
            cout << i << " -> " ;
            for(int j = 0 ; j < V ; j++)
            {
                if(matrix[i][j]!=0)
                    cout << j << "@" <<matrix[i][j] << " , " ;
            }
            cout << endl ;
        }
    }

    bool DFS(int src, int dst, bool* visited)
    {
        // visited mark
        visited[src] = true ;

        // dst ?
        if(src == dst)
            return true ;

        // nbrs
        for(int j = 0 ; j < V ; j++)
        {
            if(matrix[src][j]!=0 && !visited[j])
            {
                if(DFS(j,dst,visited) == true) 
                    return true ;
            }
        }

        return false ;
    }

    bool DFS(int src, int dst)
    {
        bool visited[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;
        return DFS(src, dst, visited) ;
    }


} ;

int main()
{

    Graph g(10) ;

    g.addEdge(0,1,10) ;
    g.addEdge(1,2,20) ;
    g.addEdge(2,3,30) ;
    g.addEdge(3,0,40) ;
    g.addEdge(3,4,50) ;
    g.addEdge(4,5,60) ;
    g.addEdge(5,6,70) ;
    g.addEdge(4,6,80) ;

    g.addEdge(7,8,80) ;
    g.addEdge(8,9,80) ;
    g.addEdge(7,9,80) ;

    g.display() ;

    cout << g.DFS(0,7) << endl ;
}