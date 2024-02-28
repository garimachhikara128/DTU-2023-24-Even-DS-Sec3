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

    int getFirst()
    {
        return head->data ;
    }

    int getLast()
    {
        // loop to reach till last node
        Node *temp = head ;
        while(temp->next != NULL)
            temp = temp ->next ;

        return temp->data ;
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
        }
        else
        {
            // 2. reach to the last node
            Node *temp = head ;
            while(temp->next != NULL)
                temp = temp->next ;
            
            // 3. linking
            temp->next = nn ;
        }

    }

    void addFirst(int item)
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

    void addAt(int item, int idx)
    {
        if(idx == 0)
            addFirst(item) ;
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
        }
        else
        {
            // 1. reach till last 2nd node
            Node *temp = head ;
            while(temp->next->next != NULL)
                temp = temp->next ;
            
            // 2. store last node as well
            Node *lastNode = temp->next ;

            // 3. linking
            temp->next = NULL ;

            // 4. memory free
            delete lastNode ;
        }
    }

    void removeFirst()
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

    void removeAt(int idx)
    {
        if(idx == 0)
            removeFirst() ;
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

    void reverse()
    {
        Node *prev = NULL ;
        Node *curr = head ;
        
        while(curr != NULL)
        {
            Node *ahead = curr->next ;
            curr->next = prev ;

            // update
            prev = curr ;
            curr = ahead ;
        }

        // important -> head update
        head = prev ;
    }

    int mid()
    {
        Node *slow = head ;
        Node *fast = head ;

        // while(fast->next != NULL && fast->next->next != NULL)
        while(fast!= NULL && fast->next != NULL)
        {
            slow = slow->next ;
            fast = fast->next->next ;
        }

        return slow->data ;
    }

    int kthFromLast(int k)
    {
        Node *slow = head ;
        Node *fast = head ;

        for(int i = 1 ; i <= k ; i++)
            fast = fast->next ;

        while(fast != NULL)
        {
            slow = slow->next ;
            fast = fast->next ;
        }

        return slow->data ;
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

    // ll->removeFirst() ;
    // ll->display() ;

    // ll->removeLast() ;
    // ll->display() ;

    // ll->removeAt(0) ;
    // ll->display() ;

    // ll->removeAt(1) ;
    // ll->display() ;

    // ll->removeAt(0) ;
    // ll->display() ;

    ll->reverse() ;
    ll->display() ;

    cout << ll->mid() << endl ;
    cout << ll->kthFromLast(4) << endl ;

    return  0 ;
}