#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// typedef struct strings{
//     char s1[50];
//     char s2;
//     int f;
// }ss;

// ss str[50];

bool wordPattern(char * pattern, char * s){
    // char *se=strtok(NULL,s);
    // int index=0;
    // while(se!="\0")
    // {
    //     for(int i=0;i<50;i++)
    //     {
    //         if(str[i].f==1)
    //         {
    //             if((strcmp(se,str[i].s1)==0))
    //             {
    //                 if(str[i].s2!=pattern[index])
    //                     return 0;
    //             }
    //         }
    //         else if(str[i].f!=1)
    //         {
    //             strcpy(str[i].s1,se);
    //             str[i].s2=pattern[index];
    //             str[i].f=1;
    //         }
    //     }
    //     index++;
    // }
    return 1;
}

int main(){
    char pattern[50];
    char s[50];
    scanf(“%[^\n]s”, s);
    fflush(stdin);
    scanf("%s",pattern);
    printf("%d",wordPattern(pattern,s));
    return 0;
}