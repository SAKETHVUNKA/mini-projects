#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    struct node* USER=users;
    if(USER==NULL)
    {
        return NULL;
    }
    else if(USER->id==key)
    {
        return USER;
    }
    else
    {
        if(USER->id>key)
        {
            search(key,USER->left);
        }
        else
        {
            search(key,USER->right);
        }
    }
}

int onlysearch(int key, struct node *users)
{
    struct node* USER=users;
    if(USER==NULL)
    {
        return 0;
    }
    else if(USER->id==key)
    {
        return 1;
    }
    else
    {
        if(USER->id>key)
        {
            search(key,USER->left);
        }
        else
        {
            search(key,USER->right);
        }
    }
}

//see document for explanattion
struct node* refineUser(struct node *user, struct node *users)
{
    int c;
    user->left=NULL;
    user->right=NULL;
    while((c=onlysearch(user->id,users)))
    {
        user->id+=1;
    }
    if(user->numfren==0)
    {
        return user;
    }
    else
    {
        int num[user->numfren];
        int count=0;
        int delete=0;
        for(int i=0;i<user->numfren;i++)
        {
            if(onlysearch(user->friends[i],users))
            {
                num[i]=1;
                count++;
            }
            else
            {
                num[i]=0;
            }
        }
        int numfrens=user->numfren;
        for(int i=0;i<numfrens;i++)
        {
            if(num[i]==0)
            {
                for(int j=i-delete;j<(user->numfren-1);j++)
                {
                    user->friends[j]=user->friends[j+1];
                }
                user->numfren--;
                delete++;
            }
        }
        if(user->numfren==0)
        {
            user->friends[0]=-1;
        }
        for(int i=0;i<user->numfren;i++)
        {
            struct node *temp=search(user->friends[i],users);
            temp->friends[temp->numfren++]=user->id;
        }
        return user;
    }
}

//insert user with id
struct node* insertUser(struct node *root,int id,struct node *user)
{
    if(root==NULL)
    {
        return user;
    }
    else
    {
        struct node *p=root;
        struct node *q=NULL;
        while(p!=NULL)
        {
        if(p->id>id)
        {
            q=p;
            p=p->left;
        }
        else
        {
            q=p;
            p=p->right;
        }
        }
        if(q->id<id)
        {
            q->right=user;
            return root;
        }
        else if(q->id>id)
        {
            q->left=user;
            return root;
        }
    }
}

//prints friends list
void friends(int id, struct node *users) 
{
    struct node *NOD=search(id,users);
    if(NOD==NULL)
    {
        //printf("");
    }
    else if(NOD->numfren==0)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=0;i<NOD->numfren;i++)
        {
            printf("%d\n",NOD->friends[i]);
        }
    }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) 
{
    struct node *is = node;
    if(is->right->left==NULL)
    {
        return is;
    }
    else
    {
        is=is->right;
        while(is->left->left!=NULL)
        {
            is=is->left;
        }
        return is;
    }
}

//deletes itself from its friend's nodes
struct node *deleteFriends(int key, struct node*users)
{
    struct node *user=search(key,users);
    if(user!=NULL)
    {
    for(int i=0;i<user->numfren;i++)
    {
        struct node *temp=search(user->friends[i],users);
        for(int j=0;j<temp->numfren;j++)
        {
            if(temp->friends[j]==user->id)
            {
                for(int k=j;k<(temp->numfren-1);k++)
                {
                    temp->friends[k]=temp->friends[k+1];
                }
                temp->numfren--;
            }
        }   
    }
    }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
    struct node *node=search(key,root);
    if(node==NULL)
    {
        return root;
    }
    else
    {
        struct node *curr=root;
        struct node *previous=NULL;
        while((curr!=NULL)&&(curr->id!=key))
        {
            previous=curr;
            if(curr->id>key)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
        if((curr->left==NULL)&&(curr->right==NULL))
        {
            if(curr==root)
            {
                free(curr);
                return NULL;
            }
            else if(curr==previous->left)
            {
                free(curr);
                previous->left=NULL;
                return root;
            }
            else
            {
                free(curr);
                previous->right=NULL;
                return root;
            }
        }
        else if((curr->right==NULL)&&(curr->left!=NULL))
        {
            if(curr==root)
            {
                struct node *tempreturn=curr->left;
                free(curr);
                return tempreturn;
            }
            else if(curr==previous->left)
            {
                previous->left=curr->left;
                free(curr);
                return root;
            }
            else
            {
                previous->right=curr->left;
                free(curr);
                return root;
            }
        }
        else if((curr->left==NULL)&&(curr->right!=NULL))
        {
            if(curr==root)
            {
                struct node *tempreturn=curr->right;
                free(curr);
                return tempreturn;
            }
            else if(curr==previous->left)
            {
                previous->left=curr->right;
                free(curr);
                return root;
            }
            else
            {
                previous->right=curr->right;
                free(curr);
                return root;
            }
        }
        else if((curr->left!=NULL)&&(curr->right!=NULL))
        {
            int roota=0;
            if(node==root)
            {
                roota=1;
            }
            struct node *isprev=minValueNode(node);
            struct node *is=NULL;
            if(isprev==node)
            {
                is=node->right;
            }
            else
            {
                is=isprev->left;
            }
            node->id=is->id;
            node->numfren=is->numfren;
            for(int i=0;i<node->numfren;i++)
                node->friends[i]=is->friends[i];
            strcpy(node->name,is->name);
            if(is==isprev->left)
            {
                isprev->left=is->right;
            }
            else if(is==isprev->right)
            {
                isprev->right=is->right;
            }
            free(is);
            if(roota)
            {
                return node;
            }
            return root;
        }
    }
}

//Print USER's IDs in ascending order
void printInOrder(struct node* myusers) 
{
    if(myusers!=NULL)
    {
        printInOrder(myusers->left);
        printf("%d %s\n",myusers->id,myusers->name);
        printInOrder(myusers->right);
    }
}


int main(int argc, char **argv)
{
    int lines;
    node *users=NULL;   
    FILE *fptr;

    if ((fptr = fopen("sample_input3.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    fscanf(fptr,"%d", &lines);
    printf("%d\n",lines);
    for(int i = 0; i < lines; i++)
    {

        int opt, id;
        fflush(stdin);
        
        fscanf(fptr,"%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                fscanf(fptr,"%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                fscanf(fptr,"%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                fscanf(fptr,"%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                fscanf(fptr,"%d", &id);
                friends(id, users);
                break;

            case 5:
                printf("############\n");
                printInOrder(users);
                printf("############\n");
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input!\n");
                break;
        }

    }
    return 0;
}