#include<iostream>

using namespace std ;

void toss(int, string) ;

int main()
{
    toss(7, "") ;
    return 0 ;
}

void toss(int n, string ans)
{
    if(n == 0)
    {
        cout << ans << endl ;
        return ;
    }

    toss(n-1, ans + "H") ;
    toss(n-1, ans + "T") ;
}