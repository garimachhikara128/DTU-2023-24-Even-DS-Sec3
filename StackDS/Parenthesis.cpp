#include<iostream>
#include<stack>

using namespace std ;

bool parenthesis(string str)
{
    stack<char> st ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if(ch == '[' || ch == '{' || ch == '(')
        {
            st.push(ch) ;
        }
        else
        {
            if(st.empty())
                return false ;
            
            else if (ch == ')' && st.top() == '(')
                st.pop() ;

            else if (ch == '}' && st.top() == '{')
                st.pop() ;

            else if (ch == ']' && st.top() == '[')
                st.pop() ;
            
            else
                return false ;
        }

    }

    return st.empty() ; 

}

int main()
{
    string str = "[()]{}{" ;

    cout << (parenthesis(str) == 1 ? "true" : "false") << endl ;

    return 0 ;
}
