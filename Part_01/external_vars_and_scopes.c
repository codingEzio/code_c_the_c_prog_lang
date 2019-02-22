#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

/*
    Variable here are defined (& space being allocated)
    -- So if you wanna use it inside, the only thing 
    -- you need to do is "tell the func u wanna use the external one"

    The code inside (or saying "code using external vars")
    can actually omit the `extern` (ALA this appears at the top)
    -- But um.. It depends (one file only OR mul-files sharing the same set)
*/
int max;               // max len seen so far
char line[MAXLINE];    // current input line (saved)
char longest[MAXLINE]; // longest line saved for now

int getln(void);
void copy(void);

int main()
{
    /*
    Print the longest input line when exit :)
    */

    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getln()) > 0)
    {
        printf("Inside<mainWhile>\n");
        if (len > max)
        {
            printf("Inside<mainWhile-If>\n");

            max = len;
            copy();

            printf("Inside<mainWhile-IfAfter[max=%2d]>\n", max);
        }
    }

    if (max > 0)
    {
        printf("\nLongest line: %s", longest);
    }

    return 0;
}

int getln(void)
{
    /*
    The `extern TYPE VAR` is just a declaration here,
    since the actual variables are already defined (& allocated).
    */
    extern char line[];

    int c, i;

    for (i = 0;
         i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n';
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

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}