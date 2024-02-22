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


} ;

int main()
{

    return  0 ;
}