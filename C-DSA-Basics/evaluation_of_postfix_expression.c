#include <stdio.h>
#include <ctype.h>
typedef struct stack
{
    char s[20];
    int top;
} STACK;
STACK st;

void push(char c)
{
    if (st.top == 20 - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        st.top++;
        st.s[st.top] = c;
    }
}

char pop()
{
    char c;
    if (st.top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        c = st.s[st.top];
        st.top--;
    }
    return c;
}

int power(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return a * power(a, b - 1);
    }
}

float postEval(char post[])
{
    int result, op1, op2;
    char c;
    for (int i = 0; post[i] != '\0'; i++)
    {
        c = post[i];
        if (isdigit(c))
        {
            push(c - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (c)
            {
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '^':
                result = power(op1, op2);
                break;
            default:
                printf("NO");
            }
            push(result);
        }
    }
    return result;
}

int main()
{
    st.top = -1;
    printf("Enter postfix expression\n");
    char postFix[20];
    gets(postFix);
    int res = postEval(postFix);
    printf("Answer : %d\n", res);
}