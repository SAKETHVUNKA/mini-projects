#include <stdio.h>
#include <string.h>

int shiftTable[26];

void shiftTableMake(char *pattern, int pL)
{
    for (int i = 0; i < 26; i++)
        shiftTable[i] = pL;
    for (int j = 0; j < pL - 1; j++)
        if ((pattern[j] - 'a') < 26 && (pattern[j] - 'a') >= 0)
            shiftTable[pattern[j] - 'a'] = pL - 1 - j;
}

int horspoolMatching(char *pattern, int pL, char *text, int tL)
{
    int i = pL - 1;

    while (i <= tL - 1)
    {
        int k = 0;
        while (k <= pL - 1 && pattern[pL - 1 - k] == text[i - k])
            k++;
        if (k == pL)
            return i - pL + 1;
        else
        {
            if (text[i] - 'a' > 25 || text[i] - 'a' < 0)
                i = i + pL;
            else
                i = i + shiftTable[text[i] - 'a'];
        }
    }
    return -1;
}

int main()
{
    char text[100];
    char pattern[50];

    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);

    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    shiftTableMake(pattern, patternLen);

    int res = horspoolMatching(pattern, patternLen, text, textLen);

    if (res == -1)
        printf("The pattern couldn't be matched. 🫤\n");
    else
        printf("The pattern was found at index: %d.", res);

    return 0;
}