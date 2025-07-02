#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max1 20
#define max2 100

typedef struct NODE
{
    char key[max1],value[max2];
    struct NODE *r,*l;
}N;

typedef struct tree
{
    N* root;
}T;

void init(T *t)
{
    t->root=NULL;
}

int isempty(T* t)
{
    if(t->root==NULL)
        return 1;
    else    
        return 0;
}

void insert(T *t)
{
    N *temp=malloc(sizeof(N));
    temp->r=NULL;
    temp->l=NULL;
    printf("Enter the word : ");
    scanf("\n%[^\n]",&(temp->key));
    printf("Enter the meaning : ");
    scanf("\n%[^\n]",&(temp->value));
    if(t->root==NULL)
    {
        t->root=temp;
        printf("Element added successfully.\n");
    }
    else
    {
        N *p=t->root;
        N *q=NULL;
        while(p!=NULL)
        {
        if(strcmp(temp->key,p->key)<0)
        {
            q=p;
            p=p->l;
        }
        else
        {
            q=p;
            p=p->r;
        }
        }
        if(strcmp(q->key,temp->key)<0)
        {
            q->r=temp;
            printf("Element added successfully.\n");
        }
        else if(strcmp(q->key,temp->key)>0)
        {
            q->l=temp;
            printf("Element added successfully.\n");
        }
    }
}

int count(N *root)
{
    N *p=root;
    int lc,rc;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        lc=count(p->l);
        rc=count(p->r);
        return (lc+rc+1);
    }
}

void search(N *root,char ele[max1])
{
    N *p=root;
    if(p==NULL)
    {
        printf("Element not found .\n");
    }
    else if(strcmp(p->key,ele)==0)
    {
        printf("Element found .\n");
    }
    else
    {
        if(strcmp(p->key,ele)>0)
        {
            search(p->l,ele);
        }
        else
        {
            search(p->r,ele);
        }
    }
}

void inorder(N *root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        printf(" %s : %s ,",root->key,root->value);
        inorder(root->r);
    }
}

void preorder(N *root)
{
    if(root!=NULL)
    {
        printf(" %s : %s ,",root->key,root->value);
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(N *root)
{
    if(root!=NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf(" %s : %s ,",root->key,root->value);
    }
}

N *del(N *root,char ele[max1])
{
    N *curr=root;
    N *previous=NULL;
    while((curr!=NULL)&&(strcmp(curr->key,ele)!=0))
    {
        previous=curr;
        if(strcmp(curr->key,ele)>0)
        {
            curr=curr->l;
        }
        else
        {
            curr=curr->r;
        }
    }
    if(curr==NULL)
    {
        printf("Element not found .\n");
        return root;
    }
    else
    {
    if((curr->r==NULL)||(curr->l==NULL))
    {
        N *q=NULL;
        if(curr->l==NULL)
        {
            q=curr->r;
        }
        else
        {
            q=curr->l;
        }
        if(previous==NULL)
        {
            free(curr);
            return q;
        }
        if(curr==previous->l)
        {
            previous->l=q;
            free(curr);
            return root;
        }
        else
        {
            previous->r=q;
            free(curr);
            return root;
        }
    }
    else
    {
            N *reserve=curr->r;
            N *rprev=NULL;
            while(reserve->l!=NULL)
            {
                rprev=reserve;
                reserve=reserve->l;
            }
            strcpy(curr->key,reserve->key);
            if(rprev!=NULL)
            {
                rprev->l=reserve->r;
            }
            else
            {
                curr->r=reserve->r;
            }
            free(reserve);
            return root;
    }
    }
}

int main()
{   
    T tree;
    int n=1,c;
    init(&tree);
    char word[max1],meaning[max2];
    while(n)
    {
        printf("1) Insert.\n2) Display in order.\n3) Display in Pre-order.\n4) Display in Post order.\n5) Delete.\n6) Search.\n7) Count.\n8) Exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:insert(&tree);
            break;
            case 2:inorder(tree.root);
                   printf("\n");
            break;
            case 3:preorder(tree.root);
                   printf("\n");
            break;
            case 4:postorder(tree.root);
                   printf("\n");
            break;
            case 5:printf("Enter the word to be deleted.\n");
                   char wordt[max1];
                   scanf("\n%[^\n]",&wordt);
                   tree.root=del(tree.root,wordt);
            break;
            case 6:printf("Enter the element to be searched : ");
                   scanf("\n%[^\n]",&wordt);
                   search(tree.root,wordt);
            break;
            case 7:printf("the number of nodes in the BST is : %d.\n",count(tree.root));
            break;
            case 8:n=0;
            break;
            default : printf("Enter a valid option. \n\n");
            break;
        }
    }
    
    return 0;
}
