#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct stack
{
    char s[max];
    int top;
} STACK;

void  push(STACK *st,char c)
{
    if(st->top==max-1)
    {
        printf("Overflow .\n");
    }
    else
    {
        st->top++;
        st->s[st->top]=c;
    }
}

char pop(STACK *st)
{
    if(st->top==-1)
    {
        printf("Underflow .\n");
        return ('\0');
    }
    else
    {
        return (st->s[st->top]);
    }
}

int isempty(STACK *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

STACK* init(STACK *st)
{
    st=(STACK*)malloc(sizeof(STACK));
    st->top=-1;
    return st;
}

void match(STACK *st,char *a)
{
    char a1,pop1;
    char check;
    int i=0;
    while((a1=a[i])!='\0')
    {
        switch(a1)
        {
            case '(':push(st,a1);
                     break;
            case '{':push(st,a1);
                     break;
            case '[':push(st,a1);
                     break;
            case ')':check=st->s[st->top];
                     if(check=='(')
                     {
                     pop1=pop(st);
                     st->top--;
                     }
                     else
                     {
                        printf("Parentheses are unbalanced .");
                        return ;
                     }
                     break;
            case '}':if((st->s[st->top])=='{')
                     {
                     pop1=pop(st);
                     st->top--;
                     }
                     else
                     {
                        printf("Parentheses are unbalanced .");
                        return ;
                     }
                     break;
            case ']':if((st->s[st->top])=='[')
                     {
                     pop1=pop(st);
                     st->top--;
                     }
                     else
                     {
                        printf("Parentheses are unbalanced .");
                        return ;
                     }
                     break;
            default:break;
        }
        i++;
    }
    int c=isempty(st);
    if(c)
    {
        printf("Parentheses are balanced .\n");
    }
    else
    {
        printf("Parentheses are unbalanced .\n");
    }
}

int main()
{
    STACK *stt;
    stt=init(stt);
    printf("Enter the string .\n");
    scanf("%s",&(stt->s));
    match(stt,stt->s);

    return 0;
}