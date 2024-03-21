#include<iostream>

using namespace std ;

class StackLL
{
    class Node
    {   
        public :

        int data ;
        Node *next ;

        Node(int data)
        {
            this->data = data ;
            this->next = NULL ;
        }
    } ;

    Node *head = NULL ;

    public :

    int top()
    {
        return head->data ;
    }

    void push(int item)
    {
        // 1. new node create
        Node *nn = new Node(item) ;

        if(head == NULL)
        {
            head = nn ;
        }
        else
        {   
            // 2. linking
            nn->next = head ;
            head = nn ;
        }

    }

    void pop()
    {
        if(head->next == NULL)
        {
            delete head ;
            head = NULL ;
        }
        else
        {
            Node *newHead = head->next ;
            delete head ;
            head = newHead ;
        }
    }

} ;

int main()
{

    StackLL *ll= new StackLL() ;

    ll->push(10) ;
    ll->push(20) ;
    ll->push(30) ;
    ll->push(40) ;
    ll->push(50) ;
    ll->push(100) ;

    cout << ll->top() << endl ;
    ll->pop() ;
    cout << ll->top() << endl ;
    ll->pop() ;
    cout << ll->top() << endl ;

    return  0 ;
}