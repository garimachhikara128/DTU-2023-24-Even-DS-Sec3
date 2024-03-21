#include<iostream>

using namespace std ;

class LinkedList
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

    void display()
    {
        Node *temp = head ;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp ->next ;
        }

        cout << endl ;
    }

    int size()
    {
        int count = 0 ;
        Node *temp = head ;
        while(temp != NULL)
        {
            count++ ;
            temp = temp ->next ;
        }
        return count ;

    }

    int getFirst()
    {
        return head->data ;
    }

    int getLast()
    {
        return tail->data ;
    }

    int getAt(int idx)
    {
        Node *temp = head ;

        for(int i = 1  ; i <= idx ; i++)
            temp = temp ->next ;
        
        return temp->data ;
    }

    void addLast(int item)
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

    void addFirst(int item)
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
            // 2. linking
            nn->next = head ;
            head = nn ;
        }

    }

    void addAt(int item, int idx)
    {
        if(idx == 0)
            addFirst(item) ;
        else if(idx == size())
            addLast(item) ;
        else 
        {
            // 1. new node create
            Node *nn = new Node(item) ;

            // 2. idx-1 node reach
            Node *temp = head ;
            for(int i = 1 ; i <= idx-1 ; i++)
                temp = temp->next ;
            
            // 3. linking
            nn->next = temp->next ;
            temp->next = nn ;
        }
    }

    void removeLast()
    {
        if(head->next == NULL)
        {
            delete head ;
            head = NULL ;
            tail = NULL ;
        }
        else
        {
            // 1. reach till last 2nd node
            Node *temp = head ;
            while(temp->next->next != NULL)
                temp = temp->next ;
            
            // 2. store last node as well
            Node *lastNode = temp->next ;

            // 3. de-linking
            temp->next = NULL ;

            // 4. memory free
            delete lastNode ;

            // 5. tail update
            tail = temp ;
        }
    }

    void removeFirst()
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

    void removeAt(int idx)
    {
        if(idx == 0)
            removeFirst() ;
        else if(idx == size()-1)
            removeLast() ;
        else 
        {
            // 1. reach the node before the desired delete
            Node *temp = head ;
            for(int i = 1 ; i <= idx-1 ; i++)
                temp = temp->next ;
            
            // 2. access to the node to be deleted
            Node *temp1 = temp->next ;

            // 3. links set
            temp->next = temp1->next ;

            // 4. memory free
            delete temp1 ;
        }

    }

} ;

int main()
{

    LinkedList *ll= new LinkedList() ;

    ll->addFirst(10) ;
    ll->display() ;
    ll->addLast(20) ;
    ll->display() ;
    ll->addFirst(30) ;
    ll->display() ;
    ll->addAt(40,2) ;
    ll->display() ;
    ll->addAt(50,1) ;
    ll->display() ;
    ll->addAt(100,1) ;
    ll->display() ;

    cout << ll->getFirst() << endl ;
    cout << ll->getLast() << endl ;
    cout << ll->getAt(3) << endl ;

    ll->removeFirst() ;
    ll->display() ;

    ll->removeLast() ;
    ll->display() ;

    ll->removeAt(0) ;
    ll->display() ;

    ll->removeAt(1) ;
    ll->display() ;

    ll->removeAt(0) ;
    ll->display() ;

    return  0 ;
}