#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int getln(char line[], int limit);

int main()
{
    int len;
    char line[MAXLINE];

    // The only thing you need to care about
    // is the returned value of `getln(line, MAXLINE)` (>80 <=80)
    while ((len = getln(line, MAXLINE)) > 0)
    {
        // Since the returned variable (of `getln`)
        // is also the index of an array (NEW_ARRAY <= INPUT)
        if (len > LIMIT)
        {
            // At the same time, the variable `i` (of `getln`)
            // can also indicates the length of the string, so..
            // we could comparing it directly with the cond (80) :D
            printf("--- Exceeded maximum!--- \n");
            printf("%s", line);
        }
    }

    return 0;
}

int getln(char line[], int limit)
{
    /*
    A more detailed explanation
    (or debugging I'd say) is stored at `impl_getline_copy.c`.

    In short, the process could be explained as 
    -- actually, 
        the `getln` itself (from my recent learning)
        is kinda an improved version of `c = getchar()) != EOF` :)
    -- so what's new? (compare to `getchar..EOF` only)
        1. Adding limit (we don't actually "need" this)
        2. Handling '\n' cleverly ( two cases: { '\n', '...\n' } )
        3. Adding '\0' to the end of string array (ah, this's required)
        4. Copying chars ( abc {<FOR>} a, b, c ) to a new array (we need it)
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