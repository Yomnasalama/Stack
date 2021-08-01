#include <bits/stdc++.h>

using namespace std;

class Mystack{
    stack<char> st;
    stack<string>st2;
public:
    int precedence(char c){
        if(c == '^')
            return 3;
        else if(c == '/' || c == '*')
            return 2;
        else if(c == '+' || c == '-')
            return 1;
        return -1;
    }
    //Convert Infix Expression to Postfix Expression
    void infix_postfix(string s){
        string res;
        for(int i = 0; i < s.length(); i++){
            if('0' <= s[i] && s[i] <= '9')
                res += s[i];
            else if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')'){
                while(st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(precedence(s[i]) <= precedence(st.top()) && st.size() != 0){
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while(st.size() != 0){
            res += st.top();
            st.pop();
        }
        cout<<res<<endl;
    }

    //Convert Postfix Expression to Prefix Expression
    void postifix_prefix(string s){
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if('0' <= s[i] && s[i] <= '9')
                st2.push(string(1, s[i]));
            else{
                string s2 = st2.top();
                st2.pop();
                string s3 = st2.top();
                st2.pop();
                st2.push(s[i]+s3+s2);
            }
        }
        while(st2.size() != 0){
            res += st2.top();
            st2.pop();
        }
        cout<<res<<endl;
    }

    //Check for balanced parentheses in an expression
    bool balances_parentheses(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            if(s[i] == ')') {
                if(st.top() == ']' || st.top() == '}')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == ']'){
                if(st.top() == ')' || st.top() == '}')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == '}') {
                if (st.top() == ']' || st.top() == ')')
                    return false;
                else
                    st.pop();
            }
        }

        if(st.size() != 0)
            return false;
        return true;
    }

    //Delete middle element of a stack
    void delete_middle(stack<int> &s){
        stack<int>temp;
        int n = s.size() / 2;
        for(int i = 0; i < n; i++){
            temp.push(s.top());
            s.pop();
        }
        s.pop();

        for(int i = 0; i < n; i++){
            s.push(temp.top());
            temp.pop();
        }
    }

    //Expression contains redundant bracket or not
    bool redundant_bracket(string s){
        bool b = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                b = false;
                while(st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                        b = true;
                    st.pop();
                }
               st.pop();
               if(!b)
                return true;
            }
            else
                st.push(s[i]);
        }
    return false;
    }

    //Range Queries for Longest Correct Bracket Subsequence
    int longest_sequence(string s, int k, int l){
        for(int i = k; i <= l; i++){
            if(s[i] == '(')
                st.push(s[i]);
            else
            {
                if(st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        return (l - k + 1) - st.size();
        while(st.size() != 0)
            st.pop();
    }

};

int main()
{
    Mystack obj;
    obj.infix_postfix("(1+3)*(3+4)");



}
