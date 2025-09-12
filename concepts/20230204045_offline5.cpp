#include <bits/stdc++.h>
using namespace std;

int priority(char s)
{
    if (s == '^')
        return 100;
    else if (s == '*' || s == '/')
        return 50;
    else if (s == '+' || s == '-')
        return 10;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    stack<char> stk;
    string postfix = "";

    for (int i = 0; i < infix.size(); i++)
    {
        char target = infix[i];
        if (target == ' ')
            continue;

        if (isdigit(target))
        {
            string num = "";
            while (i < infix.size() && isdigit(infix[i]))
            {
                num += infix[i];
                i++;
            }
            i--;
            postfix += num + ' ';
        }

        else if (target == '(')
            stk.push(target);
            
        else if (target == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else
        {
            while (!stk.empty() && priority(stk.top()) >= priority(target))
            {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            stk.push(target);
        }
    }

    while (!stk.empty())
    {
        postfix += stk.top();
        postfix += ' ';
        stk.pop();
    }

    return postfix;
}

double numberConverter(const string &postfix, int &i)
{
    double num = 0;
    while (i < postfix.size() && isdigit(postfix[i]))
    {
        num = num * 10 + (postfix[i] - '0');
        i++;
    }
    i--;
    return num;
}

double evaluate(string postfix)
{
    stack<double> st;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] == ' ')
            continue;

        if (isdigit(postfix[i]))
        {
            st.push(numberConverter(postfix, i));
        }
        else
        {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            double sum = 0;

            if (postfix[i] == '+')
                sum = b + a;
            else if (postfix[i] == '-')
                sum = b - a;
            else if (postfix[i] == '*')
                sum = b * a;
            else if (postfix[i] == '/')
                sum = b / a;
            else if (postfix[i] == '^')
                sum = pow(b, a);

            st.push(sum);
        }
    }
    return st.top();
}

int main()
{
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluate(postfix) << endl;

    return 0;
}
