#include<iostream>
#include<stack>

using namespace std ;

int main()
{
    int arr[]= {50,30,20,40,10,45,5,60,8,15} ;
    int N = sizeof(arr) / sizeof(int) ;

    stack<int> st ;

    for(int i = 0 ; i < N ; i++)
    {
        while(!st.empty() && st.top() < arr[i])
        {
            cout << st.top() << "->" << arr[i] << endl ;
            st.pop() ;
        }

        st.push(arr[i]) ;
    }

    while(!st.empty())
    {
        cout << st.top() << "-> -1" << endl;
        st.pop() ;
    }



    return 0 ;
}