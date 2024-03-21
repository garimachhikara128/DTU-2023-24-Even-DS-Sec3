#include<iostream>

using namespace std ;

class QueueLL
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
    Node *tail = NULL ;

    public :

    int get()
    {
        return head->data ;
    }

    void enqueue(int item)
    {
        // 1. new node create
        Node *nn = new Node(item) ;

        if(head == NULL)
        {
            head = nn ;
            tail = nn ;
        }
        else
        {
           tail->next = nn ;
           tail = nn ;
        }

    }

    void dequeue()
    {
        if(head->next == NULL)
        {
            delete head ;
            head = NULL ;
            tail = NULL ;
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

    QueueLL *ll= new QueueLL() ;

    ll->enqueue(10) ;
    ll->enqueue(20) ;
    ll->enqueue(30) ;
    ll->enqueue(40) ;
    ll->enqueue(50) ;

    cout << ll->get() << endl ;
    ll->dequeue() ;
    cout << ll->get() << endl ;
    ll->dequeue() ;
    cout << ll->get() << endl ;
    ll->dequeue() ;

    return  0 ;
}