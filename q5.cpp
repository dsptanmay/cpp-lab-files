#include <iostream>
#include <cmath>
#include <stack>
#include <ctype.h>

using namespace std;
class Expression
{
private:
    char infix[30];
    char postfix[30];
    stack<char> s;

public:
    Expression()
    {
        cout << "Enter a valid infix expression: " << endl;
        cin.getline(infix, 30);
    }

    int precedence(char sym)
    {
        switch (sym)
        {
        case '#':
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return -1;
        }
    }
    void convert()
    {
        int i, j = 0;
        char sym, ch;
        for (i = 0; infix[i] != '\0'; i++)
        {
            sym = infix[i];
            if (isalnum(sym))
            {
                postfix[j++] = sym;
            }
            else
            {
                switch (sym)
                {
                case '(':
                    s.push('(');
                    break;

                case ')':
                    while ((ch = s.top()) != '(')
                    {
                        postfix[j++] = ch;
                        s.pop();
                    }
                default:
                    while (precedence(sym) <= precedence(s.top()))
                    {
                        if (sym == s.top() && precedence(sym) == 3)
                        {
                            break;
                        }
                        postfix[j++] = s.top();
                        s.pop();
                    }
                    s.push(sym);
                }
            }
        }

        while (s.top() != '#')
        {
            postfix[j++] = s.top();
            s.pop();
        }

        cout << "Resultant Postfix Expression is:" << postfix;
        return;
    }

    void display()
    {
        cout << "Infix expression is : " << infix << endl;
        cout << "Postfix expression is : " << postfix << endl;
        return;
    }
};

int main()
{
    Expression e;
    e.convert();
    e.display();
    return 0;
}