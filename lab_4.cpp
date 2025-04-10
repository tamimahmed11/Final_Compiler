#include<bits/stdc++.h>
using namespace std;
bool isOperator(char ch) 
{
    return ch == '+'|| ch == '-' || ch == '*' || ch == '/';
}
bool isDigit(char ch) 
{
    return ch >= '0' && ch <= '9';
}
bool isValidExpression(const string& expr) 
{
    for (size_t i = 0; i < expr.length(); i++) 
    {
        char ch = expr[i];
        if (!isDigit(ch) && !isOperator(ch) && ch != ' ' && ch != '(' && ch != ')') {
            return false;
        }
        if (isOperator(ch)) 
        {
            if (i == 0 || i == expr.length() - 1) 
            {
                return false;
            }
       
            char prev = expr[i - 1];
            char next = expr[i + 1];
            if (!isDigit(prev) && prev != ')' && !isDigit(next) && next != '(') 
            {
                return false;
            }
        }
    }
  // parenthesis dhekbo
    stack<char> st;
    for (char ch : expr) 
    {
        if (ch == '(') 
        {
            st.push(ch);
        } else if (ch == ')') 
        {
            if (st.empty() || st.top() != '(') 
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isValidExpression(expr)) 
    {
        cout << "Valid Expression" << endl;
    } else 
    {
        cout << "Invalid Expression" << endl;
    }
    return 0;
}

