#include<iostream>

using namespace std ;

class BST
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

    BST(int *arr, int n)
    {
        root = construct(arr, 0, n-1) ;
    }

    Node* construct(int *arr, int lo, int hi)
    {
        if(lo > hi)
            return NULL ;

        int mid = (lo+hi)/2 ;

        Node *nn = new Node(arr[mid]) ;
        nn->left = construct(arr, lo, mid-1) ;
        nn->right = construct(arr,mid+1, hi) ;

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

    // size and height are dependent on shape, hence we can use the same fxns that we used in BT
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
        if(node->right == NULL)
            return node->data ;

        return maximum(node->right) ;
        
    }

    bool find(int item)
    {
        return find(root, item) ;
    }

    bool find(Node *node, int item)
    {
        if(node == NULL)
            return false ;

        if(item < node->data)  
            return find(node->left, item) ;
        else if(item > node->data)
            return find(node->right, item) ;
        else 
            return true ;
    }

    void add(int item)
    {
        root = add(root, item) ;
    }

    Node *add(Node *node, int item)
    {
        if(node == NULL)
        {
            Node *nn = new Node(item) ;
            return nn ;
        }

        if(item <= node->data)
            node->left = add(node->left, item) ;
        else
            node->right = add(node->right, item) ;

        return node ;
    }

    void remove(int item)
    {
        root = remove(root, item) ;
    }

    Node* remove(Node *node, int item)
    {
        if(node == NULL)
            return node ;

        if(item < node->data)
            node->left = remove(node->left, item) ;
        else if (item > node->data)
            node->right = remove(node->right, item) ;
        else 
        {
            // case1 
            if(node->left == NULL && node->right == NULL)
            {
                delete node ;
                return NULL ;
            }
            // case 2
            else if(node->left != NULL && node->right == NULL)
            {
                Node *temp = node->left ;
                delete node ;
                return temp ;
            }
            // case 3
            else if(node->left == NULL && node->right != NULL)
            {
                Node *temp = node->right ;
                delete node ;
                return temp ;
            }
            // case 4
            else if(node->left != NULL && node->right != NULL)
            {
                int max = maximum(node->left) ;
                remove(node->left, max) ;
                node->data = max ;
                return node ;
            }

        }   

        return node ;

    }


} ;

int main()
{
    int arr[] = {} ;
    int n = sizeof(arr) / sizeof(arr[0]) ;

    BST *bst = new BST(arr,n) ;

    bst->display() ;

    bst->add(100) ;
    bst->add(50) ;
    bst->add(200) ;
    bst->add(30) ;
    bst->add(70) ;
    bst->add(250) ;
    bst->add(10) ;
    bst->add(55) ;
    bst->add(80) ;
    bst->add(220) ;
    bst->add(300) ;
    bst->add(52) ;
    bst->add(57) ;
    bst->add(90) ;
    bst->add(51) ;
    bst->add(53) ;

    bst->display() ;

    cout << bst->size() << endl ;
    cout << bst->height() << endl ;
    cout << bst->maximum() << endl ;
    cout <<  bst->find(60) << endl ;

    bst->remove(300) ;
    bst->remove(200) ;
    bst->remove(30) ;
    bst->remove(70) ;

    bst->display() ;

    return 0 ;
}