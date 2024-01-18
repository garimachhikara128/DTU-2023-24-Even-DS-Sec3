#include<iostream>

using namespace std ;

void mazePath(int, int, int, int, string) ;

int main()
{
    int m = 7 ;
    int n = 2 ;
    mazePath(0,0,m-1,n-1,"") ;
    return 0 ;
}

void mazePath(int cr, int cc, int er, int ec, string ans)
{
    // +ve base case
    if(cr == er && cc == ec)
    {
        cout << ans << endl ;
        return ;
    }

    if(cr > er || cc > ec)
        return ;

    mazePath(cr, cc+1, er, ec, ans + "H") ;
    mazePath(cr+1, cc, er, ec, ans + "V") ;
}