#include<iostream>

using namespace std ;

class BT
{
    class Node
    {
        public :

        int data ;
        Node *left ;
        Node *right ;

        Node(int data)
        {
            this->data = data ;
            this->left = NULL ;
            this->right = NULL ;
        }
    } ;

    Node *root = NULL;

    public :

    BT()
    {
        root = construct(NULL, 0) ;
    }

    Node* construct(Node* node, int ilc)
    {
        if(node == NULL)
            cout << "Enter the data for root node ?" << endl ;
        else 
            if(ilc)
                cout << "Enter the data for left child of " << node->data << endl ;
            else
                cout << "Enter the data for right child of " << node->data << endl ;

        int data ;
        cin >> data ;

        Node *nn = new Node(data) ;

        int hlc, hrc ;

        cout << nn->data << " has a left child ?" ;
        cin >> hlc ;

        if(hlc)
            nn->left = construct(nn, 1) ;

        cout << nn->data << " has a right child ?" ;
        cin >> hrc ;

        if(hrc)
            nn->right = construct(nn, 0) ;

        return nn ;
        
    }

    void display()
    {
        cout << endl << "------------------" << endl ;
        display(root) ;
        cout << "------------------" << endl ;
    }

    void display(Node *node)
    {
        if(node == NULL)
            return ;

        // self work
        if(node->left == NULL)
            cout << "." ;
        else 
            cout << node->left->data  ;

        cout << " -> " << node->data << " <- " ;

        if(node->right == NULL)
            cout << "." ;
        else 
            cout << node->right->data ;

        cout << endl ;

        // smaller problems
        display(node->left) ;
        display(node->right) ;
    }

    int size()
    {
        return size(root) ;
    }

    int size(Node *node)
    {
        if(node == NULL)
            return 0 ;

        int ls = size(node->left) ;
        int rs = size(node->right) ;

        return ls + rs + 1 ;
    }

    int height()
    {
        return height(root) - 1;
    }

    int height(Node *node)
    {
        if(node == NULL)
            return 0 ;

        int lh = height(node->left) ;
        int rh = height(node->right) ;

        return max(lh,rh) + 1 ;
    }

    int maximum()
    {
        return maximum(root) ;
    }

    int maximum(Node *node)
    {
        if(node == NULL)
            return INT_MIN ;

        int lm = maximum(node->left) ;
        int rm = maximum(node->right) ;

        return max(node->data, max(lm,rm)) ;
    }

    bool find(int item)
    {
        return find(root, item) ;
    }

    bool find(Node *node, int item)
    {
        if(node == NULL)
            return false ;

        if(node->data == item)  
            return true ;

        bool lf = find(node->left, item) ;
        bool rf = find(node->right, item) ;

        return lf || rf ;
    }

} ;
int main()
{
    BT* bt = new BT() ;
    bt->display() ;

    cout << bt->size() << endl ;
    cout << bt->height() << endl ;
    cout << bt->maximum() << endl ;
    cout <<  bt->find(600) << endl ;

    return 0 ;
}
// 10 1 20 1 40 0 0 1 50 0 0 1 30 1 60 1 70 0 0 0 0 