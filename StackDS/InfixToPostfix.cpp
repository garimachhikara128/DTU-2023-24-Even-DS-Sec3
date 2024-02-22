#include<iostream>
#include<stack>

using namespace std ;

int prec(char ch)
{
    if(ch == '*' || ch == '/')
        return 2 ;
    else if(ch == '+' || ch == '-')
        return 1 ;
    else 
        return 0 ;
}

string conversion(string str)
{
    stack<char> st ;
    string ans = "" ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            ans += ch ;
        else if (ch == '(')
            st.push(ch) ;
        else if(ch == ')')
        {
            while(st.top() != '(')
            {
                ans += st.top() ;
                st.pop() ;
            }

            st.pop() ;
        }
        else
        {
            while(!st.empty() && prec(st.top()) > prec(ch))
            {
                ans += st.top() ;
                st.pop() ;
            }

            st.push(ch) ;
        }
    }

    while(!st.empty())
    {
        ans += st.top() ;
        st.pop() ;
    }

    return ans ;
}

int main()
{
    string str = "((A+B)-C*(D/E))+F" ;

    cout << conversion(str) << endl ;

    return 0 ; 
}