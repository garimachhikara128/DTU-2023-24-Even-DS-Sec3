#include<iostream>
#include<vector>

using namespace std ;

    void downheapify(int *arr, int pi, int N)
    {
        int mini = pi ;

        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        if(lci < N && arr[lci] > arr[mini])
            mini = lci ;

        if(rci < N && arr[rci] > arr[mini])
            mini = rci ;

        if(mini != pi)
        {
            swap(arr[pi], arr[mini]) ;
            downheapify(arr,mini,N) ; 
        }

    }

    void heapSort(int *arr, int N)
    {
        // heap
        for(int i = N/2-1 ; i >=0 ; i--)
            downheapify(arr,i,N) ; 

        // sort
        for(int i = N-1 ; i >=1 ; i--)
        {
            swap(arr[0],arr[i]) ;
            downheapify(arr,0,i) ;
        }
    }

    void display(int *arr, int N)
    {
        for(int i = 0 ; i < N ; i++)
            cout << arr[i] << " " ;
        cout << endl ;
    }

int main()
{
    int arr[] = {10,100,50,5,7,20,60} ;
    int N = 7 ;
    heapSort(arr,N) ;
    display(arr,N);
    
    return 0 ;
}