#include<iostream>
#include<queue>

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

    BT(int *pre, int *in, int n)
    {
        root = construct(pre, 0, n-1, in, 0, n-1) ;
    }

    Node* construct(int *pre, int plo, int phi, int *in, int ilo, int ihi)
    {
        if(ilo > ihi || plo > phi)
            return NULL ;

        Node *nn = new Node(pre[plo]) ;

        int si = -1 ;
        int nel = 0 ; 
        for(int i = ilo ; i <= ihi ; i++)
        {
            if(in[i] == pre[plo])
            {
                si = i ;
                break ;
            }
            nel++ ;
        }

        // left
        nn->left = construct(pre, plo+1, plo+nel, in, ilo, si-1) ;

        // right
        nn->right = construct(pre, plo+nel+1, phi, in, si+1, ihi) ;

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

    void levelOrderTraversal()
    {
        queue<Node*> q ;

        q.push(root) ;

        while(!q.empty())
        {
            // 1. remove
            Node *rn = q.front() ;
            q.pop() ;

            // 2. print
            cout << rn->data << " " ;

            // 3. child
            if(rn->left != NULL)
                q.push(rn->left) ;
            if(rn->right != NULL)
                q.push(rn->right) ;
        }
        cout << endl ;
    }

    void display2()
    {
        display2(root) ;
    }

    void display2(Node *node)
    {
        if(node == NULL)
            return ;
        
        cout << "Hii " << node->data << endl ;

        display2(node->left) ;
        cout << "Coming back from left child of " << node->data << " and going towards right child " << endl ;
        display2(node->right) ;

        cout << "Bye " << node->data << endl ;
    }

    void preorder()
    {
        preorder(root) ;
        cout << endl ;
    }

    void preorder(Node *node)
    {
        if(node == NULL)
            return ;
        
        cout << node->data << " " ;
        preorder(node->left) ;
        preorder(node->right) ;
    }

    void inorder()
    {
        inorder(root) ;
        cout << endl ;
    }

    void inorder(Node *node)
    {
        if(node == NULL)
            return ;
        
        inorder(node->left) ;
        cout << node->data << " " ;
        inorder(node->right) ;
    }

    void postorder()
    {
        postorder(root) ;
        cout << endl ;
    }

    void postorder(Node *node)
    {
        if(node == NULL)
            return ;
        
        postorder(node->left) ;
        postorder(node->right) ;
        cout << node->data << " " ;
    }


} ;
int main()
{
    int pre[] = {10,20,40,50,90,30,60,70,80} ;
    int in[] = {40,20,90,50,10,30,70,60,80} ;
    int n = sizeof(pre) / sizeof(pre[0]) ;

    BT *bt = new BT(pre, in, n) ;

    // BT* bt = new BT() ;
    bt->display() ;

    cout << bt->size() << endl ;
    cout << bt->height() << endl ;
    cout << bt->maximum() << endl ;
    cout <<  bt->find(600) << endl ;

    bt->levelOrderTraversal() ;

    bt->display2() ;

    bt->preorder() ;
    bt->inorder() ;
    bt->postorder() ;

    return 0 ;
}
// 10 1 20 1 40 0 0 1 50 0 0 1 30 0 1 60 0 0 