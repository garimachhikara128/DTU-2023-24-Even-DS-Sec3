#include<iostream>
#include<stack>

using namespace std ;

int evaluate(string str)
{
    stack<int> st ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if(ch >= '0' && ch <= '9')
            st.push(ch - '0') ;
        else
        {
            int e1 = st.top() ;
            st.pop() ;
            int e2 = st.top() ;
            st.pop() ;

            if(ch == '+')
                st.push(e2 + e1) ;
            else if(ch == '-')
                st.push(e2 - e1) ;
            else if(ch == '*')
                st.push(e2 * e1) ;
            else if(ch == '/')
                st.push(e2 / e1) ;  
        }      
    }

    return st.top() ;

}

int main()
{
    string str = "231*+9-" ;

    cout << evaluate(str) << endl ;

    return 0 ;
}
