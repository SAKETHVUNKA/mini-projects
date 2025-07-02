#include<stdio.h>
#include<ctype.h>

#define max 20

typedef struct stack
{
    char s[max];
    int top;
}STACK;
STACK st;

void push(char x)
{
    if(st.top==max-1)
    {
        printf("Overflow .\n");
    }
    else
    {
        st.top++;
        st.s[st.top]=x;
    }
}

char pop()
{
    char x;
    if(st.top==-1)
    {
        printf("Underflow .\n");
        return '\0';
    }
    else
    {
        x=st.s[st.top];
        st.top--;
        return x;
    }
}

int isempty()
{
    if(st.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// void in_to_post(char in[]);

int is_pre(char sym)
{
    if(sym=='^')
    {
        return 3;
    }
    else if(sym=='*' || sym=='/')
    {
        return 2;
    }
    else if(sym=='+' || sym=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void in_to_post(char a[])
{
    int i=0,j=0;
    char post[20];
    char x,x1;
    while((x=a[i]))
    {
        if(isalnum(x))
        {
            post[j]=x;
            i++;
            j++;
        }
        else if(x=='(')
        {
            push(x);
            i++;
        }
        else if(x==')')
        {
            while((x1=pop())!='(')
            {
                post[j]=x1;
                j++;
            }
            i++;
        }
        else
        {
            while(is_pre(x)<=is_pre(st.s[st.top]))
            {
                post[j]=pop();
                j++;
            }
            push(x);
            i++;
        }
    }
    while(!(isempty()))
    {
        post[j++]=pop();
    }
    post[j++]='\0';
    puts(post);
}

int main()
{
    st.top=-1;
    char infix[max];
    printf("Enter the string .");
    gets(infix);
    printf("The postfix expression is : \n");
    in_to_post(infix);
    return 0;
}