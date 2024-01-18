#include<iostream>

void PI(int) ;

using namespace std ;

int main()
{
    cout << "Hii" << endl ;
    PI(5) ;
    cout << "Bye" << endl ;
    return 0 ;
}

void PI(int n)
{
    if(n == 0)
        return ;
        
    PI(n-1) ;
    cout << n << endl ;

}

