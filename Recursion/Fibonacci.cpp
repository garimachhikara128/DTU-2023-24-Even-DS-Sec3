#include<iostream>

using namespace std ;

int fib(int) ;
void fibonacci(int, int, int, int) ;

int main()
{
    // for(int i = 1 ; i <= 100 ; i++)
    //     cout << i << "\t" << fib(i) << endl;
    fibonacci(0,1,20,1) ;

    return 0 ;
}

void fibonacci(int a, int b, int n, int i)
{
    if(i == n)
        return ;

    cout << a << endl ;
    int sum = a + b ;
    fibonacci(b,sum, n, i+1) ;
}

int fib(int n)
{
    if(n == 0 || n == 1) 
        return n ;

    int fnm1 = fib(n-1) ;
    int fnm2 = fib(n-2) ;
    int fn = fnm1 + fnm2 ;

    return fn ;
}