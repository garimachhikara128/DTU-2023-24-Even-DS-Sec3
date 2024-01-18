#include<iostream>

using namespace std ;

void parenthesis(int, int, int, string) ;

int main()
{
    parenthesis(7,0,0,"") ;
    return 0 ;
}

void parenthesis(int n, int open, int close, string ans)
{
    if(open == n && close == n)
    {
        cout << ans << endl ;
        return ;
    }

    if(open > n || close > n || close > open)
        return ;

    parenthesis(n, open+1, close, ans + "(") ;
    parenthesis(n, open, close+1, ans + ")") ;
    
}