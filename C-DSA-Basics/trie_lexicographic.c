#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE (255)
#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE]; // pointer Array
    bool isEndOfWord;                         // denotes end of the word
};

// Initialise Default Node by setting the pointer Array to Null and End of World to False
struct TrieNode *getNode()
{
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// Function that returns the length of the Input
int my_strlen(char *string)
{
    int c=0;
    while(string[c]!='\0')
    {
        c++;
    }
    return c;
}

// Function to Insert the element into the Trie
void insert(struct TrieNode *root, char *key)
{
    struct TrieNode *curr=root;
    for(int i=0;key[i]!='\0';i++)
    {
        int index=key[i]-'a';
        if(curr->children[index]==NULL)
        {
            curr->children[index]=getNode();
        }
        curr=curr->children[index];
    }
    curr->isEndOfWord=1;
}

// Recursive Function to Print in Lexicographic order using DFS
void dfs_word(struct TrieNode *root, char *word, int *plent)
{
    struct TrieNode *curr=root;
    for(int i=0;i<26;i++)
    {
        if(curr->children[i]!=NULL)
        {
            word[(*plent)++]=i+'a';
            if(curr->children[i]->isEndOfWord)
            {
                for(int j=0;j<*(plent);j++)
                {
                    printf("%c",word[j]);
                }
                printf("\n");
            }
            dfs_word(curr->children[i],word,plent);
        }
    }
    (*plent)--;
}

// Function to Display
void display(struct TrieNode *root)
{
    char word[MAXSIZE] = "";
    int length = 0;
    dfs_word(root, word, &length);
}

int main()
{
    int number_of_ele, i;
	
	// Number of input elements
    scanf("%d", &number_of_ele);
	char input[number_of_ele][MAXSIZE];
    for (i = 0; i < number_of_ele; i++)
    {
        scanf("%s", input[i]);
    }

    // initialising root node
    struct TrieNode *root = getNode();  

    // Inserting Into the Trie
    for (int i = 0; i < ARRAY_SIZE(input); i++)
    {
        insert(root, input[i]);
    }

    display(root);
    return 0;
}