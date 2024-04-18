#include<iostream>
#include<vector>

using namespace std ;

class MinHeap
{
    int *data ;
    int N ;

    public :

    void add(int *arr, int N)
    {
        this->data = arr ;
        this->N = N ;

        for(int i = N/2-1 ; i >=0 ; i--)
            downheapify(i) ; 
    }

    int remove()
    {
        swap(data[0],data[N-1]) ;
        int rv = data[N-1] ;
        N-- ;
        downheapify(0) ;
        return rv ;
    }

    void downheapify(int pi)
    {
        int mini = pi ;

        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        if(lci < N && data[lci] < data[mini])
            mini = lci ;

        if(rci < N && data[rci] < data[mini])
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
        for(int i = 0 ; i < N ; i++)
            cout << data[i] << " " ;
        cout << endl ;
    }

} ;

int main()
{
    int arr[] = {10,100,50,5,7,20,60} ;
    int N = sizeof(arr)/sizeof(arr[0]) ;
    MinHeap h ;
    h.add(arr,N) ;

    cout << h.remove() << endl ;
    // h.display() ;
    cout << h.remove() << endl ;
    // h.display() ;
    cout << h.remove() << endl ;
    // h.display() ;
    cout << h.remove() << endl ;
    cout << h.remove() << endl ;
    cout << h.remove() << endl ;
    
    return 0 ;
}