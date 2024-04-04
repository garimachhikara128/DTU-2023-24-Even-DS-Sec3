#include<iostream>
#include<vector>

using namespace std ;

class MinHeap
{
    vector<int> data ;

    public :

    void add(int item)
    {
        data.push_back(item) ;
        upheapify(data.size()-1) ;
    }

    void upheapify(int ci)
    {
        int pi = (ci-1)/2 ;

        if(data[ci] < data[pi])
        {
            swap(data[pi],data[ci]) ;
            upheapify(pi) ;
        }
    }

    int remove()
    {
        swap(data[0],data[data.size()-1]) ;
        int rv = data[data.size()-1] ;
        data.pop_back() ;
        downheapify(0) ;
        return rv ;
    }

    void downheapify(int pi)
    {
        int mini = pi ;

        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        if(lci < data.size() && data[lci] < data[mini])
            mini = lci ;

        if(rci < data.size() && data[rci] < data[mini])
            mini = rci ;

        if(mini != pi)
        {
            swap(data[pi], data[mini]) ;
            downheapify(mini) ; 
        }

    }

    int get()
    {
        return data[0] ;
    }

    void display()
    {
        for(int i = 0 ; i < data.size() ; i++)
            cout << data[i] << " " ;
        cout << endl ;
    }

} ;

int main()
{
    MinHeap h ;

    h.add(100) ;
    h.display() ;
    h.add(200) ;
    h.display() ;
    h.add(300) ;
    h.display() ;
    h.add(50) ;
    h.display() ;
    h.add(60) ;
    h.display() ;
    h.add(150) ;
    h.display() ;

    cout << h.remove() << endl ;
    h.display() ;
    cout << h.remove() << endl ;
    h.display() ;
    cout << h.remove() << endl ;
    h.display() ;
    
    return 0 ;
}