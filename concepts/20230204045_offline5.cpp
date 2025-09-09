#include<bits/stdc++.h>
using namespace std;

stack<char> stk; 

int priority(char s)
{
    if(s=='^')
        return 100;
    else if(s=='*'||s=='/')
        return 50;
    else if (s=='+'||s=='-')
        return 10;
    else
        return 0;
}

int evaluate(string str)
{
    stack<int> st; 

    for(int i =0; i< str.size(); i++)
    {
        int sum=0;

        if(isdigit(str[i]))
            st.push(str[i]-'0');

        else if(str[i]=='+')
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            sum=(b+a);
            st.push(sum);
        }
        else if(str[i]=='-')
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            sum=(b-a);
            st.push(sum);
        }
        else if(str[i]=='*')
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            sum=(b*a);
            st.push(sum);
        }
        else if(str[i]=='/')
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            sum=(b/a);
            st.push(sum);
        }
        else if(str[i]=='^')
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            sum=pow(b,a);
            st.push(sum);
        }
    }
    return st.top();
}

int main ()
{
    string infix,postfix="";
    cin>>infix;

    for(int i=0; i<infix.size(); i++)
    {
        char target=infix[i];

        if(target>='0'&&target<='9')
        {
            postfix=postfix+target;
        }
        else if(target=='(')
        {
            stk.push(target);
        }
        else if(target==')')
        {
            while(!stk.empty()&&stk.top()!='(')
            {
               postfix=postfix+stk.top();
               stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(!stk.empty() && priority(stk.top()) >= priority(target))
            {
                 postfix=postfix+stk.top();
                 stk.pop();
            }
            stk.push(target);
        }
    }
    while(!stk.empty())
    {
         postfix=postfix+stk.top();
         stk.pop();
    }

    cout<<postfix<<endl;
    cout<<evaluate(postfix)<<endl;

    return 0;
}
