#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE
{
    struct NODE *child[26];
    int word;
}node;

int length=0;
int word[100];

typedef struct tstack
{
    node *no;
    int index;
}stack;

stack s[100];
int top=-1;

void push(node *n,int i)
{
    if(top<100)
    {
        top++;
        s[top].index=i;
        s[top].no=n;
    }
}

stack pop()
{
    if(top>-1)
    {
        return s[top--];
    }
}

node* getnode()
{
    node* temp=malloc(sizeof(node));
    for(int i=0;i<26;i++)
    {
        temp->child[i]=NULL;
    }
    temp->word=0;
    return temp;
}

void displaylen(node *root,int len)
{
    node *curr=root;
    for(int i=0;i<26;i++)
    {
        if(curr->child[i]!=NULL)
        {
            word[length++]=i+'a';
            if((curr->child[i]->word)&&(length==len))
            {
                for(int j=0;j<length;j++)
                {
                    printf("%c",word[j]);
                }
                printf("\n");
            }
            displaylen(curr->child[i],len);
        }
    }
    length--;
}

void display(node *root,int f,char *pre)
{
    node *curr=root;
    for(int i=0;i<26;i++)
    {
        if(curr->child[i]!=NULL)
        {
            word[length++]=i+'a';
            if(curr->child[i]->word)
            {
                if(f==0)
                {
                    for(int j=0;j<length;j++)
                    {
                        printf("%c",word[j]);
                    }
                }
                else if(f==1)
                {
                    printf("%s",pre);
                    for(int j=0;j<length;j++)
                    {
                        printf("%c",word[j]);
                    }
                }
                printf("\n");
            }
            display(curr->child[i],f,pre);
        }
    }
    length--;
}

void displaypre(node *root,char *pre)
{
    printf("\n");
    node *curr=root;
    int i;
    for(i=0;pre[i]!='\0';i++)
    {
        int val=pre[i]-'a';
        curr=curr->child[val];
    }
    int j=1;
    if(curr->word==1)
    {
        printf("%s\n",pre);
    }
    display(curr,j,pre);
}

void insert(node *root,char *word)
{
    node *curr=root;
    for(int i=0;word[i]!='\0';i++)
    {
        int index=word[i]-'a';
        if(curr->child[index]==NULL)
        {
            curr->child[index]=getnode();
        }
        curr=curr->child[index];
    }
    curr->word=1;
}

int search(node *root,char *word)
{
    node *curr=root;
    for(int i=0;word[i]!='\0';i++)
    {
        int index=word[i]-'a';
        if(curr->child[index]==NULL)
        {
            return 0;
        }
        curr=curr->child[index];
    }
    if(curr->word)
    {
        return 1;
    }
    return 0;
}

int check(node *nod)//returns number of keys activated in the array of given node . 
{
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(nod->child[i]!=NULL)
        {
            count++;
        }
    }
    return count;
}

void delete(node *root,char *word)
{
    node *curr=root;
    for(int i=0;word[i]!='\0';i++)
    {
        int index=word[i]-'a';
        if(curr->child[index]==NULL)
        {
            printf("The given word is not present in the trie .\n");
            return;
        }
        push(curr,index);
        curr=curr->child[index];
    }
    push(curr,-1);
    curr->word=0;
    while(1)
    {
        stack x=pop();
        if(x.index!=-1)
        {
            x.no->child[x.index]=NULL;
        }
        if(x.no==root)
        {
            return;
        }
        int k=check(x.no);
        if((k>=1)||(x.no->word==1))
        {
            return;
        }
        else
        {
            if(x.index==-1)
            {
                x.no=NULL;
            }
            free(x.no);
        }
    }
}

int main()
{
    node* root=getnode();
    char word[100];
    int ch,n=1;
    while(n)
    {
        printf("Enter your choice :\n1)Insert .\n2)Display .\n3)Display Length  .\n4)Display Prefix .\n5)Search .\n6)Delete .\n7)Exit .\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the word .\n");
                    scanf("%s",word);
                    insert(root,word);
                    break;
            case 2: length=0;
                    int i=0;
                    char pre[100];
                    display(root,i,pre);
                    break;
            case 3: length=0;
                    printf("Enter the length .\n");
                    int len;
                    scanf("%d",&len);
                    displaylen(root,len);
                    break;
            case 4: length=0;
                    printf("Enter the prefix .\n");
                    // char pre[100];
                    scanf("%s",pre);
                    displaypre(root,pre);
                    break;
            case 5: printf("Enter the word to be searched .\n");
                    scanf("%s",word);
                    int key=search(root,word);
                    if(key==1)
                    {
                        printf("It is present .\n");
                    }
                    else
                    {
                        printf("not Found .\n");
                    }
                    break;
            case 6: printf("Enter the word to be deleted .\n");
                    scanf("%s",pre);
                    delete(root,pre);
                    break;
            case 7: n=0;
                    break;
            default :printf("Enter a valid choice .\n");
            break; 
        }
    }
    return 0;
}