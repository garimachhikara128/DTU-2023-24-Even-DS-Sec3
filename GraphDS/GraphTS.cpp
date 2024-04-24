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

    void helper(int src, bool* visited, stack<int> &s)
    {
        // visited mark
        visited[src] = true ;

        // nbrs
        for(int j = 0 ; j < V ; j++)
        {
            if(matrix[src][j]!=0 && !visited[j])
            {
                helper(j,visited,s) ;
            }
        }

        // stack answer push
        s.push(src) ;
    }

    static bool compare(vector<int> vec1 , vector<int> vec2)
    {
        return vec1[1] < vec2[1] ;
    }

    void topologicialSort()
    {
        bool visited[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        stack<int> s ;

        vector<vector<int> > outdegree ;

        for(int i = 0 ; i < V ; i++)
        {
            int count = 0 ;
            for(int j = 0; j < V ; j++)
            {
                if(matrix[i][j] != 0) 
                    count++ ;
            }

            outdegree.push_back({i,count}) ;
        }

        sort(outdegree.begin(), outdegree.end(), compare) ;

        // printing
        // for(int i = 0 ; i < outdegree.size() ; i++)
        // {
        //     vector<int> sv = outdegree[i] ;
        //     for(int j = 0 ; j < sv.size() ; j++)
        //     {
        //         cout << sv[j] << " " ;
        //     }
        //     cout << endl ;
        // }

        for(auto vertex_info : outdegree)
        {
            int v = vertex_info[0] ;

            if(visited[v])
                continue ;

            helper(v,visited,s) ;
        }

        while(!s.empty())
        {
            cout << s.top() << " " ;
            s.pop() ;
        }

        cout << endl ;
    }

} ;

int main()
{

    Graph g(6) ;

    g.addEdge(5,0,10) ;
    g.addEdge(5,2,20) ;
    g.addEdge(2,3,30) ;
    g.addEdge(3,1,40) ;
    g.addEdge(4,0,50) ;
    g.addEdge(4,1,60) ;

    g.display() ;

    g.topologicialSort() ;

    return 0 ;
}