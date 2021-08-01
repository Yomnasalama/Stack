#include <bits/stdc++.h>


using namespace std;
const int N= 50;
stack<char> st;

string reverse_string(string phrase)
{
    string new_phrase;
    int phrase_size = phrase.size();
    stack<char> temp;
    for(int i = 0; i < phrase_size; i++)
    {
        temp.push(phrase[i]);
    }
    for(int i = 0; i < phrase_size; i++)
    {
        new_phrase += temp.top();
        temp.pop();
    }
    return new_phrase;
}

string convert_postfix_infix(string expression)
{
    stack<string> temp;
    char c = ' ';
    string new_expression = "", temp_expression = "", operand1 = "", operand2 = "";
    int expression_size = expression.size();
    for (int i = 0; i < expression_size; i++)
    {
        c = expression[i];
        if(c == '*' || c == '/' || c == '^' || c == '+' || c == '-' )
        {
            operand1 = temp.top();
            temp.pop();
            operand2 = temp.top();
            temp.pop();
            new_expression = "(" + operand2 + c + operand1 + ")";
            temp.push(new_expression);
        }
        else
        {
            temp_expression = c;
            temp.push(temp_expression);
        }
    }
    string result=temp.top();
    temp.pop();
    return result;
}



float evaluate_postfix(string expression)
{
    stack<float> temp;
    int expression_size = expression.size();
    string num = "";
    int temp_num = 0;


    for (int i = 0; i < expression_size; i++)
    {
        if(expression[i] == '#')
        {
            i++;
            int j = i;
            while(isdigit(expression[j]))
            {
                num += expression[j];
                j++;
            }
            i = j - 1;
            stringstream toInt(num);
            toInt >> temp_num;
            temp.push(temp_num);
            num = "";
        }
        else
        {
            int val1 = temp.top();
            temp.pop();
            int val2 = temp.top();
            temp.pop();
            switch (expression[i])
            {
                case '+': temp.push(val1 + val2); break;
                case '-': temp.push(val2 - val1); break;
                case '*': temp.push(val2 * val1); break; break;
                case '/': temp.push(val2 / val1); break;
            }
        }
    }
    return temp.top();
}

int minimum_brackets(string brackets)
{
     int size = brackets.length();
     stack<char> myStack;


    if (size % 2 != 0)
       return -1;
    for (int i = 0; i < size; i++)
    {
        if (brackets[i]=='}' && !myStack.empty())
        {
            if (myStack.top()=='{')
                myStack.pop();
            else
                myStack.push(brackets[i]);
        }
        else
            myStack.push(brackets[i]);
    }

    int n = 0;
    while (!myStack.empty() && myStack.top() == '{')
    {
        myStack.pop();
        n++;
    }
    int m = myStack.size();

    return (ceil(m / 2) + ceil(n / 2));
}


int removeConsecutive(vector<string> v)
{
  stack<string> st;

    for (int i=0; i<v.size(); i++)
    {

        if (st.empty())
            st.push(v[i]);
        else
        {
            string str = st.top();


            if (str == v[i])
                st.pop();

            else
                st.push(v[i]);
        }
    }

    return st.size();
}

string reverse_int(int num)
{
  string str;
  stringstream ss;
  ss << num;
  ss >> str;;
  return reverse_string(str);
}


bool ifDublication(string expression)
{
     stack<char> Stack;
     int size = expression.size();
     char ch;

    for (int i = 0; i < size; i++ )
    {
        ch = expression[i];
        if (ch == ')')
        {
            char top = Stack.top();
            Stack.pop();

            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = Stack.top();
                Stack.pop();
            }
            if(elementsInside <= 1) {
                return 1;
            }
        }
        else
            Stack.push(ch);
    }

    return false;
}







int main()
{
   string phrase ="123/-14/5-*";
  // cout << convert_postfix_infix(phrase);
       //cout << evaluate_postfix("#11#35+#3#4+*");

   // cout << minimum_brackets("}{{}}{{{") << endl;

  //  vector<string> v = { "ab", "aa", "aa", "bcd", "ab"};
    //cout << removeConsecutive(v);

    //cout << reverse_int(345);
    cout << ifDublication("(((a+(b))+(c+d)))");

    return 0;
}
