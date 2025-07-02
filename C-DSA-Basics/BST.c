#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int key;
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
    printf("Enter the element : ");
    scanf("%d",&(temp->key));
    printf("%d\n",temp->key);
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
        if(p->key>temp->key)
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
        if(q->key<temp->key)
        {
            q->r=temp;
            printf("Element added successfully.\n");
        }
        else if(q->key>temp->key)
        {
            q->l=temp;
            printf("Element added successfully.\n");
        }
    }
}

void reinsert(N *root,N *temp)
{
	if(temp->key<root->key)
	{
		if(root->l==NULL)
		{
			root->l=temp;
		}
		else
		{
			reinsert(root->l,temp);
		}
	}
	else if(temp->key>root->key)
	{
		if(root->r==NULL)
		{
			root->r=temp;
		}
		else
		{
			reinsert(root->r,temp);
		}
    }
}

void max(N *root)
{
    if(root->r==NULL)
    {
        printf("Max value is : %d.\n",root->key);
    }
    else
    {
        max(root->r);
    }
}

void min(N *root)
{
    if(root->l==NULL)
    {
        printf("Max value is : %d.\n",root->key);
    }
    else
    {
        min(root->l);
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

void search(N *root,int ele)
{
    N *p=root;
    if(p==NULL)
    {
        printf("Element not found .\n");
    }
    else if(p->key==ele)
    {
        printf("Element found .\n");
    }
    else
    {
        if(p->key>ele)
        {
            search(p->l,ele);
        }
        else
        {
            search(p->r,ele);
        }
    }
}

void insertre1(T *t)
{
    N *temp;
    temp=(N*)malloc(sizeof(N));
    temp->r=NULL;
    temp->l=NULL;
    printf("Enter the elment : ");
    scanf("%d",&(temp->key));
    printf("%d\n",temp->key);
    if(t->root==NULL)
    {
        t->root=temp;
    }
    else
    {
        reinsert(t->root,temp);
    }
}

void inorder(N *root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        printf(" %d ",root->key);
        inorder(root->r);
    }
}

void preorder(N *root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->key);
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
        printf(" %d ",root->key);
    }
}

N *del(N *root,int ele)
{
    N *curr=root;
    N *previous=NULL;
    while((curr!=NULL)&&(curr->key!=ele))
    {
        previous=curr;
        if(curr->key>ele)
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
        curr->key=reserve->key;
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
    int n=1,c,ele=0;
    init(&tree);
    while(n)
    {
        printf("1) Insert.\n2) Display in order.\n3) Display in Pre-order.\n4) Display in Post order.\n5) Max.\n6) Min\n7) Delete.\n8) Destroy.\n9) Recursive Insert.\n10) Search.\n11) Count.\n12) Exit.\n");
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
            case 5:max(tree.root);
            break;
            case 6:min(tree.root);
            break;
            case 7:printf("Enter the element to be deleted.\n");
                   int eled;
                   scanf("%d",&eled);
                   tree.root=del(tree.root,eled);
            break;
            // case 8:destroy(&tree);
            // break;
            case 9: insertre1(&tree);
            break;
            case 10:printf("Enter the element to be searched : ");
                    scanf("%d",&ele);
                    search(tree.root,ele);
            break;
            case 11:printf("the number of nodes in the BST is : %d.\n",count(tree.root));
            break;
            case 12:n=0;
            break;
            default : printf("Enter a valid option. \n\n");
            break;
        }
    }
    return 0;
}