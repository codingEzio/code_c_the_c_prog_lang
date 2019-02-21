#include <stdio.h>

#define MAXLINE 1000

int getln(char line[], int limit);

int length(char line[]);
void reverse(char line[]);

int main()
{
    int len;
    char line[MAXLINE];
    char str[MAXLINE];

    while ((len = getln(line, MAXLINE)) > 0)
    {
        printf("\nMainWhile<beforeReverse>\n");
        reverse(line);
        printf("MainWhile< afterReverse>\n");

        printf("%s", line);
    }

    return 0;
}

int getln(char line[], int limit)
{
    /*
    Just in case that I forget
    -- This implementation is completely the same 
    -- as the others (might sep as a shared-lib in the future)!
    
    Still, this method is to 
    -- get the input => copy INPUT to a new array 
    -- the other code is just completing the use-cases :D 
    */

    int c, i;

    for (i = 0;
         i < limit - 1 && (c = getchar()) != EOF && c != '\n';
         ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

int length(char line[])
{
    /* Calc the len of the input string ('\n' included).
    */

    int i;

    for (i = 0; line[i] != '\0'; ++i)
    {
        ;
    }

    printf("Length<afterFor>\n");
    printf("Length<i = [%d]>\n", i);

    return i;
}

void reverse(char line[])
{
    int i_front = 0;
    int i_back = length(line);

    char temp;

    // Debug
    printf("Reverse<i_back = [%d]>\n", i_back);

    /*
    This is the awesome part (huh, not written by me, ofc).
    -- It's quite efficient since it does NOT loop all of them.
    -- I think it's more like a "binary-search" (ah, just a guess).
    */
    i_back -= 2;
    while (i_back > i_front)
    {
        printf("Reverse<insideWhileBeforeAdd>\n");

        printf("Reverse<Algorithem> [%c]\n", temp);
        temp = line[i_front];
        printf("Reverse<Algorithem> [%c]\n", line[i_front]);
        line[i_front] = line[i_back];
        printf("Reverse<Algorithem> [%c]\n", line[i_back]);
        line[i_back] = temp;

        ++i_front;
        --i_back;

        printf("Reverse<insideWhileAfterAdd>\n");
        printf("Reverse<insideWhileAfterAdd> Num[%2d][%2d]>\n", i_front, i_back);
    }

    printf("Reverse<theEndOfMethod>\n");
}