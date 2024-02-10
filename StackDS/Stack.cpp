#include<iostream>

using namespace std ;

class Stack
{
    int *arr ;
    int tos ;
    int N ;

    public :

    Stack()
    {
        int default_cap = 20 ;

        arr = new int[default_cap] ;
        tos = -1 ;
        N = default_cap ;
    }

    Stack(int cap)
    {
        arr = new int[cap] ;
        tos = -1 ;
        N = cap ;
    }

    void push(int item)
    {
        if(isFull())
        {
            cout << "Stack is Full." << endl ;
            return ;
        }

        tos ++ ;
        arr[tos] = item ;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty." << endl ;
            return ;
        }

        arr[tos] = 0 ;
        tos -- ;
    }

    int top()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty." << endl ;
            return -1 ;
        }

        return arr[tos] ;
    }

    void display()
    {
        for(int i = tos ; i >=0 ; i--)
            cout << arr[i] << "\t" ;
        cout << endl ;
    }

    bool isEmpty()
    {
        return tos == -1 ;
    }

    bool isFull()
    {
        return tos == N - 1 ;
    }

    int size()
    {
        return tos + 1 ;
    }

} ;

int main()
{
    Stack s(30) ;

    s.push(10) ;
    s.push(20) ;
    s.push(30) ;
    s.push(40) ;

    s.display() ;

    cout << s.top() << endl ;
    s.pop() ;
    s.pop() ;

    s.push(50) ;

    s.display() ;

    return 0 ;
}