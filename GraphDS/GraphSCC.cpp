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

    vector<vector<int> > getSCC()
    {
        vector<vector<int> > bv ;

        bool part_scc[V] ;
        for(int i = 0 ; i < V ; i++)
            part_scc[i] = false ;

        for(int i = 0 ; i < V ; i++)
        {
            if(part_scc[i])
                continue ;

            vector<int> sv ;
            sv.push_back(i) ;
            
            for(int j = i+1 ; j < V ; j++)
            {
                if(DFS(i,j) && DFS(j,i) && !part_scc[j])
                {
                    part_scc[j] = true ;
                    sv.push_back(j) ;
                }

            }

            bv.push_back(sv) ;
        }

        return bv ;

    }


} ;

int main()
{

    Graph g(5) ;

    g.addEdge(1,0,10) ;
    g.addEdge(0,2,20) ;
    g.addEdge(2,1,30) ;
    g.addEdge(0,3,40) ;
    g.addEdge(3,4,50) ;
    g.addEdge(2,4,50) ;
    g.addEdge(4,2,50) ;

    g.display() ;

    // cout << g.DFS(0,7) << endl ;

    vector< vector<int> > res = g.getSCC() ;

    for(int i = 0 ; i < res.size() ; i++)
    {
        vector<int> sv = res[i] ;
        for(int j = 0 ; j < sv.size() ; j++)
        {
            cout << sv[j] << " " ;
        }
        cout << endl ;
    }
}