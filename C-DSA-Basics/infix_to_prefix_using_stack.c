#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define max 100
int top=-1;
int son[max];

int EMPTY()
{
        if(top==-1)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

void PUSH(int symbol)
{
        top++;
        son[top] = symbol;
}

int POP()
{
        return (son[top--]);
}

int PRIOR(char symbol)
{
    if((symbol=='+')||(symbol=='-'))
    {
        return 1;
    }
    else if(symbol=='^')
    {
        return 3;
    }
    else if((symbol=='*')||(symbol=='/'))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int evaluate_prefix(char *prefix,int n)
{
        int op1,op2,res,result;
        for(int i=n-1;i>=0;i--)
        {
                if((prefix[i]>='0') && (prefix[i]<='9'))
                        PUSH(prefix[i]-48);
                else
                {
                        op2=POP();
                        op1=POP();
                        switch(prefix[i])
                        {
                        case '^':res=pow(op2,op1);
                                 break;
                        case '*':res=op2*op1;
                                 break;
                        case '/':res=op2/op1;
                                 break;
                        case '%':res=op2%op1;
                                 break;
                        case '+':res=op2+op1; 
                                 break;
                        case '-':res=op2-op1;
                                 break;
                        }
                        PUSH(res);
                }
        }
        result=POP();
        return result;
}

void infix_to_prefix(char *infix,char *prefix,int n)
{
        int p=0;
        char x,temp,symbol;
        for(int i=n-1;i>=0;i--)
        {
                symbol=infix[i];
                if((symbol!='\0')&&(symbol!='\t')&&(symbol!=' '))
                {
                        switch(symbol)
                        {
                            case ')':PUSH(symbol);
                                     break;
                            case '(':while((x=POP()) != ')')
                                        prefix[p++] = x;
                                     break;
                            case '+':while((!EMPTY( ))&&(PRIOR(son[top])>PRIOR(symbol)))
                                     {
                                        prefix[p++] = POP();
                                     }
                                     PUSH(symbol);
                                     break;
                            case '-':while((!EMPTY( ))&&(PRIOR(son[top])>PRIOR(symbol)))
                                     {
                                        prefix[p++] = POP();
                                     }
                                     PUSH(symbol);
                                     break;
                            case '*':while((!EMPTY( ))&&(PRIOR(son[top])>PRIOR(symbol)))
                                     {
                                        prefix[p++] = POP();
                                     }
                                     PUSH(symbol);
                                     break;
                            case '/':while((!EMPTY( ))&&(PRIOR(son[top])>PRIOR(symbol)))
                                     {
                                        prefix[p++] = POP();
                                     }
                                     PUSH(symbol);
                                     break;
                            case '%':while((!EMPTY( ))&&(PRIOR(son[top])>PRIOR(symbol)))
                                     {
                                        prefix[p++] = POP();
                                     }
                                     PUSH(symbol);
                                     break;
                            case '^':while((!EMPTY( ))&&(PRIOR(son[top])>PRIOR(symbol)))
                                     {
                                        prefix[p++] = POP();
                                     }
                                     PUSH(symbol);
                                     break;
                            default :prefix[p++]=symbol;
                        }
                }
        }
        while(!EMPTY( ))
        {
                prefix[p++] = POP();
        }
        prefix[p] ='\0'; 
        for(int i=0,j=p-1;i<j;i++,j--)
        {
                temp=prefix[i];
                prefix[i]=prefix[j];
                prefix[j]=temp;
        }
}

int main()
{
        char infix[max], prefix[max];     
        int n;
	scanf("%d", &n);
	scanf("%s", infix);
	infix_to_prefix(infix, prefix, n);
	int res = evaluate_prefix(prefix, strlen(prefix));
	printf("%s %d\n", prefix, res);
	
        return 0;    
}