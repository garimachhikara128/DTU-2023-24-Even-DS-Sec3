#include<iostream>

using namespace std ;

class Queue
{
    int *arr ;
    int front ;
    int rear ;
    int N ;
    int size ;

    public :

    Queue()
    {
        int default_cap = 20 ;

        arr = new int[default_cap] ;
        front = -1 ;
        rear = -1 ;
        size = 0 ;
        N = default_cap ;
    }

    Queue(int cap)
    {
        arr = new int[cap] ;
        front = -1 ;
        rear = -1 ;
        size = 0 ;
        N = cap ;
    }

    void enqueue(int item)
    {
        if(isFull())
        {
            cout << "Queue is Full." << endl ;
            return ;
        }

        if(empty())
        {
            front = 0 ;
            rear = 0 ;
        }
        else 
            rear = (rear +  1) % N ; 

        arr[rear] = item ;
        size ++ ;
    }

    void dequeue()
    {
        if(empty())
        {
            cout << "Queue is Empty." << endl ;
            return ;
        }

        arr[front] = 0 ;
        front = (front + 1) % N ;
        size -- ;
    }

    int get()
    {
        if(empty())
        {
            cout << "Queue is Empty." << endl ;
            return -1 ;
        }

        int item = arr[front] ;
        return item ;
    }

    bool empty()
    {
        return size == 0 ;
    }

    bool isFull()
    {
        return size == N ;
    }

    void display()
    {
        for(int i = 0 ; i < size ; i++)
        {
            int idx = (front + i) % N ;
            cout << arr[idx] << " " ;
        }
        cout << endl ;
    }

} ;

int main()
{

    Queue q(5) ;

    q.enqueue(10) ;
    q.enqueue(20) ;
    q.enqueue(30) ;
    q.enqueue(40) ;
    q.enqueue(50) ;

    q.display() ;
    q.dequeue() ;
    q.dequeue() ;
    q.dequeue() ;
    q.dequeue() ;

    q.enqueue(60) ;
    q.enqueue(70) ;
    q.enqueue(80) ;

    q.display() ;

    return 0 ;
}