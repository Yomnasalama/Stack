#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
stack<int> INT_stk;
stack<int> Max_stk;
stack<int> temp;
bool is_palindrome(string s){
    bool is_pal = true;
    for(int i = 0 ; i < s.length() ; i++){
        stk.push(s[i]);
    }
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != stk.top()){
            is_pal = false;
        }
        stk.pop();
    }
    return is_pal;
}

//Convert Prefix Expression to Infix Expression
string prefix_to_infix(string s){
    string s1 = "";
    if(!stk.empty()){
        while(!stk.empty()){
            stk.pop();
        }
    }
    for(int i = 0 ; i < s.length() ; i+=2){
        if(s[i] == '%' || s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '+' ){
            stk.push(s[i]);
        }
        else{
            s1 += s[i];
            if(!stk.empty()){
                s1 += stk.top();
                stk.pop();
            }
        }
    }
    return s1;
}

//Reverse a stack using recursion
void Reverse(){

    if(INT_stk.empty()){
        return;
    }

    temp.push(INT_stk.top());
    INT_stk.pop();
    Reverse();

}
void rec_reverse(){
    Reverse();
    INT_stk = temp;
}

//Find maximum depth of nested parenthesis in a string
int Depth(string s){
    int dep = 0;
    int Max = 0;
    if(!stk.empty()){
        while(!stk.empty()){
            stk.pop();
        }
    }
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '(' ){
            stk.push(s[i]);
            dep+=1;
        }
        else if(s[i] == ')'){
            dep-=1;
        }
        Max = max(dep,Max);
    }
    return Max;
}

//Remove brackets from an algebraic string
string remove_brackets(string s){
    if(!stk.empty()){
        while(!stk.empty()){
            stk.pop();
        }
    }
    for(int i = 0; i < s.length() ; i++){
        if(s[i]!='(' && s[i]!=')'){
            stk.push(s[i]);
        }
    }
    s = "";
    while(!stk.empty()){
        s = stk.top() + s;
        stk.pop();
    }
    return s;
}

//Find index of closing bracket for a given opening bracket in an expression
int idx_close_bracket(int x,string s){
    stack<int> brackets;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i]=='('){
            brackets.push(i);
        }
        else if(s[i]==')' && !brackets.empty()){
            if(brackets.top() == x){
                return i;
            }
            else{
                brackets.pop();
            }
        }
    }
    return -1;
}
//Tracking current Maximum Element in a Stack
int Track_Max(int x){
    if(Max_stk.size()==0){
        Max_stk.push(x);
    }
    else{
        if(Max_stk.top()<x){
            Max_stk.push(x);
        }
    }
    return Max_stk.top();
}

//Next Greater
void Next_Greater(){
    int NGE = -1;
    while(!INT_stk.empty()){
        cout<<INT_stk.top()<<" ---> "<<NGE<<endl;
        NGE = INT_stk.top();
        INT_stk.pop();
    }
}

int main()
{

    cout<<is_palindrome("racecar")<<endl;
    cout<<prefix_to_infix("* / 6 2 + 1 2")<<endl;
    cout<<Depth("((((())()())))")<<endl;
    cout<<remove_brackets("(10-2)+(1*8)")<<endl;
    cout<<idx_close_bracket(1,"(())(())())")<<endl;

    INT_stk.push(1);
    cout<<Track_Max(INT_stk.top());
    INT_stk.push(2);
    cout<<Track_Max(INT_stk.top());
    INT_stk.push(3);
    cout<<Track_Max(INT_stk.top())<<endl;
    rec_reverse();
    cout<<INT_stk.top();
    Next_Greater();
    return 0;
}
