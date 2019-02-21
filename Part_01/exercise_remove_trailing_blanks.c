#include <stdio.h>

#define MAXLINE 1000

int getln(char line[], int limit);
void remove_trailing_blanks(char line[], int length);

int main()
{
    /*
    Remove blanks? What need to be removed, exactly?
    -- 1. remove trailing blanks 
    -- 2. remove trailing tabs
    -- 3. remove lines that is filled with (all) blanks 

    In plain words (ah, examples)
    -- 1. "AB CD"      =>  "AB CD"
    -- 2. "AB CD[\t]"  =>  "AB CD" (removed)
    -- 3. "AB CD[..]"  =>  "AB CD" (removed) (.. is blank)

    Still, the debugging code will not be removed.
    At least for now, since I still not quite familiar with C.
    */

    int len;
    char line[MAXLINE];

    while ((len = getln(line, MAXLINE)) > 0)
    {
        printf("[BeforeRemove<MainWhile>]\n");
        remove_trailing_blanks(line, len);
        printf("[After<MainWhile>]\n");

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

void remove_trailing_blanks(char line[], int length)
{
    int i;

    // This `for` still got conditions i.e. { ' ' || '\t' },
    // we might actually not be able to "meet" the conditions!
    for (i = length - 2;
         line[i] == ' ' || line[i] == '\t';
         --i)
    {
        line[i + 1] = '\n';
        line[i + 2] = '\0';
        printf("[Inside<removeFor>]\n");
        printf("[Inside<removeFor[%d]>]\n", i);
    }

    printf("[Outside<removeFor[%d]>]\n", i);
}