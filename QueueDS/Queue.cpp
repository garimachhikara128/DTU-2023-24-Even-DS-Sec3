#include<iostream>

using namespace std ;

class Queue
{
    int *arr ;
    int front ;
    int rear ;
    int N ;

    Queue()
    {
        int default_cap = 20 ;

        arr = new int[default_cap] ;
        front = -1 ;
        rear = -1 ;
        N = default_cap ;
    }

    Queue(int cap)
    {
        arr = new int[cap] ;
        front = -1 ;
        rear = -1 ;
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
        
    }

    bool isFull()
    {

    }

    bool display()
    {

    }



}