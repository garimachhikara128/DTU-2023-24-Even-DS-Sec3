#include<iostream>

void draw(int) ;

using namespace std ;

int main()
{
    int inches = 5 ;
    int tick_length = 3 ;
    int i ;
    for(i = 0 ; i < inches ; i++)
    {
        // major lines print
        for(int j = 1 ; j <= tick_length ; j++)
            cout << "- " ;
        cout << i ;
        cout << endl ;

        draw(tick_length-1) ;
    }

    // major lines print
    for(int j = 1 ; j <= tick_length ; j++)
        cout << "- " ;
    cout << i ;
    cout << endl ;

    return 0 ;
}

void draw(int n)
{
    if(n == 0)
        return ;

    // SP
    draw(n-1) ;
    // work
    for(int i = 1 ; i <= n ; i++)
        cout << "- " ;
    cout << endl ;
    // SP
    draw(n-1) ;
}