#include <bits/stdc++.h>
using namespace std;
int maxim_len(string str)
{

    stack<char> my_stack;
    int n = str.length();
    int res=0;
    for(int i = 0 ; i < n ; i++)
    {
        if (str[i] == '(')
            my_stack.push(str[i]);
        else
        {
            if ( my_stack.size()!=0 &&  my_stack.top() == '(' )
            {
                my_stack.pop();
                res+=2;

            }
            else
                my_stack.push(str[i]);

        }

    }
    return res;
}

void reverseWords(string str)
{
    stack<char> my_stack;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            my_stack.push(str[i]);


        else
        {
            while (my_stack.empty() == false)
            {
                cout << my_stack.top();
                my_stack.pop();
            }
            cout << " ";
        }
    }

    while (my_stack.empty() == false)
    {
        cout << my_stack.top();
        my_stack.pop();
    }
}

bool pair_wise(stack<int> s)
{
    stack<int> my_stack;
    while (!s.empty())
    {
        my_stack.push(s.top());
        s.pop();
    }


    bool result = true;
    while (my_stack.size() > 1)
    {


        int x = my_stack.top();
        my_stack.pop();
        int y = my_stack.top();
        my_stack.pop();
        if (abs(x - y) != 1)
            result = false;


        s.push(x);
        s.push(y);
    }

    if (my_stack.size() == 1)
        s.push(my_stack.top());

    return result;
}

bool is_equevelant(string exp1, string exp2)
{
    char sign ;
    bool bracket = false ;
    stack<char> my_stack;
    stack<char> my_stack2;

    for (int i = 0 ; i < exp1.length() ; i++)
    {
        if (exp1[i] == '(')
        {
            sign = my_stack.top() ;
            bracket = true ;
        }
        else if (exp1[i] == ')')
            bracket = false;
        else
        {
            if(bracket)
            {
                if (exp1[i] != 45 && exp1[i] != 43 )
                {
                    my_stack.push(exp1[i]);
                }
                else
                {
                    if (sign == '-')
                    {
                        if(exp1[i] == '-')
                            my_stack.push('+');

                        else
                            my_stack.push('-');

                    }
                    else
                    {
                        my_stack.push(exp1[i]);
                    }
                }
            }

            else
            {
                my_stack.push(exp1[i]);
            }

        }

    }



    for (int i = 0 ; i < exp2.length() ; i++)
    {
        my_stack2.push(exp2[i]);
    }
    while (my_stack.size() != 0)
    {
        if (my_stack2.top()!= my_stack.top())
        {
            return false;
        }
        my_stack.pop();
        my_stack2.pop();
    }
    return true;

}


void leftSmaller(int arr[], int n, int SE[])
{
    stack<int>S;

    for (int i=0; i<n; i++)
    {
        while (!S.empty() && S.top() >= arr[i])
            S.pop();
        if (!S.empty())
            SE[i] = S.top();
        else
            SE[i] = 0;
        S.push(arr[i]);
    }
}


int findMaxDiff(int arr[], int n)
{
    int LS[n];


    leftSmaller(arr, n, LS);


    int RRS[n];
    reverse(arr, arr + n);
    leftSmaller(arr, n, RRS);


    int result = -1;
    for (int i=0 ; i< n ; i++)
        result = max(result, abs(LS[i] - RRS[n-1-i]));

    return result;
}







int main()
{


    return 0;

}
