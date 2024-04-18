#include<iostream>
#include<queue>

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

    bool BFS(int src, int dst)
    {
        queue<int> q ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        q.push(src) ;
        while(!q.empty())
        {
            // remove
            int rv = q.front() ;
            q.pop() ;

            if(visited[rv])
                continue ;

            // visited
            visited[rv] = true ;

            // check dst ?
            if(rv == dst)
                return true ;

            // nbrs
            for(int j = 0 ; j < V ; j++)
            {
                if(matrix[rv][j] != 0 && !visited[j])
                {
                    q.push(j) ;
                }
            }

        }

        return false ;
    }
} ;

int main()
{
    Graph g(7) ;

    g.addEdge(0,1,10) ;
    g.addEdge(1,2,20) ;
    g.addEdge(2,3,30) ;
    g.addEdge(3,0,40) ;
    g.addEdge(3,4,50) ;
    g.addEdge(4,5,60) ;
    g.addEdge(5,6,70) ;
    g.addEdge(4,6,80) ;

    g.display() ;

    cout << g.BFS(0,6) << endl ;

}