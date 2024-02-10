#include<iostream>
#include<stack>

using namespace std ;

int main()
{
    int arr[]= {20,60,40,100,80,70,200,20,50,70} ;
    int N = sizeof(arr) / sizeof(int) ;

    int ans[N] ;
    stack<int> st ;

    for(int i = 0 ; i < N ; i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop() ;
        }

        if(st.empty())
            ans[i] = i + 1 ;
        else 
            ans[i] = i - st.top() ;

        st.push(i) ;
    }

    for(int i = 0 ; i < N ; i++)
    {
        cout << ans[i] << "\t" ;
    }
    cout << endl ;



    return 0 ;
}