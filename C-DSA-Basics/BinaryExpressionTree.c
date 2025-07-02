// constructing a tree and evaluating it 
// input is a postfix expression
//one postfix array
//
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct NODE
{
    char key;
    struct NODE *r,*l;
}node;

typedef struct TREE
{
    node *root;
}tree;

typedef struct STACK
{
    int top;
    node *st[20];
}stack;

void init(stack *s,tree *t)
{
    s->top=-1;
    t->root=NULL;
}

node* pop(stack *s)
{
    if(s->top!=-1)
    {
        return ((s->st[(s->top)--]));
    }
}

void push(stack *s,node *pointer)
{
    if(s->top!=19)
    {
        s->top++;
        s->st[s->top]=pointer;
    }
}

void displayInO(node *root)
{
    node *p = root;
    if (p == NULL)
    {
        return;
    }
    else
    {
        displayInO(p->l);
        printf("%c ", p->key);
        displayInO(p->r);
    }
}

int isEmpty(tree *t)
{
    if ((t->root) == NULL)
        return 1;
    else
        return 0;
}

void display(tree *t)
{
    if (isEmpty(t))
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        displayInO(t->root);
        printf("\n");
    }
}

float evaluate(node *root)
{
    float res;
    switch (root->key)
    {
    case '+':
        res = evaluate(root->l) + evaluate(root->r);
        break;
    case '-':
        res = evaluate(root->l) - evaluate(root->r);
        break;
    case '*':
        res = evaluate(root->l) * evaluate(root->r);
        break;
    case '/':
        res = evaluate(root->l) / evaluate(root->r);
        break;
    default:
        return ((root->key) - '0');
        break;
    }
    return res;
}

void evalTree(tree *t)
{
    printf("Result: %.2f\n", evaluate(t->root));
}

int main()
{
    int i=0;
    // char postfix[20]="234*+";
    char postfix[20];
    tree t;
    stack s;
    init(&s,&t);
    printf("Enter the postfix expression : ");
    gets(postfix);
    while((postfix[i])!='\0')
    {
        char ch=postfix[i];
        node *temp=malloc(sizeof(node));
        temp->key=ch;
        temp->r=NULL;
        temp->l=NULL;
        if (isdigit(ch))
        {
            push(&s,temp);
        }
        else
        {
            node *op1,*op2;
            op2=pop(&s);
            op1=pop(&s);
            temp->l=op1;
            temp->r=op2;
            push(&s,temp);
        }
        i++;
    }
    t.root=pop(&s);
    display(&t);
    evalTree(&t);

    return 0;
}