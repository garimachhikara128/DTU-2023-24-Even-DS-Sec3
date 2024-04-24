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

    void BFT()
    {
        queue<int> q ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

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

                // print
                cout << rv << " " ;

                // nbrs
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }

            }
        }

        cout << endl ;
    }

    bool DFS(int src, int dst)
    {
        stack<int> s ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        s.push(src) ;
        while(!s.empty())
        {
            // remove
            int rv = s.top() ;
            s.pop() ;

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
                    s.push(j) ;
                }
            }

        }

        return false ;
    }

    void DFT()
    {
        stack<int> s ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            s.push(src) ;
            while(!s.empty())
            {
                // remove
                int rv = s.top() ;
                s.pop() ;

                if(visited[rv])
                    continue ;

                // visited
                visited[rv] = true ;

                // print
                cout << rv << " " ;

                // nbrs
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        s.push(j) ;
                    }
                }

            }
        }

        cout << endl ;
    }


    bool isConnected()
    {
        // count is calculating the no. of components
        int count = 0 ;

        queue<int> q ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            q.push(src) ;
            count++ ;
            while(!q.empty())
            {
                // remove
                int rv = q.front() ;
                q.pop() ;

                if(visited[rv])
                    continue ;

                // visited
                visited[rv] = true ;

                // print
                // cout << rv << " " ;

                // nbrs
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }

            }

        }

        // cout << endl ;

        return count == 1 ;
    }

    bool isCyclic()
    {
        queue<int> q ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            q.push(src) ;
            while(!q.empty())
            {
                // remove
                int rv = q.front() ;
                q.pop() ;

                if(visited[rv])
                    return true ;

                // visited
                visited[rv] = true ;

                // print
                // cout << rv << " " ;

                // nbrs
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }

            }
        }

        // cout << endl ;
        return false ;
    }

    bool isTree()
    {
        return isConnected() && !isCyclic() ;
    }

    vector< vector<int> > getConnectedComponents()
    {
        vector<vector<int> > bv ;
        queue<int> q ;
        // bool visited[V] ;
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            vector<int> sv ;
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

                // print
                sv.push_back(rv) ;

                // nbrs
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }
            }
            bv.push_back(sv) ;

        }

        return bv ;
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

    // cout << g.DFS(0,8) << endl ;
    // g.BFT() ;
    // g.DFT() ;

    cout << g.isConnected() << endl ;
    cout << g.isCyclic() << endl ;
    cout << g.isTree() << endl ;

    vector< vector<int> > res = g.getConnectedComponents() ;

    for(int i = 0 ; i < res.size() ; i++)
    {
        vector<int> sv = res[i] ;
        for(int j = 0 ; j < sv.size() ; j++)
        {
            cout << sv[j] << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}