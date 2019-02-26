#include <stdio.h>

#define MAXLINE 1000

/*
I don't really know why we need to set this to 8.
*/
#define TABWIDTH 8

int getln(char line[], int limit);
void detab(char line[], char tline[]);

int main()
{
    /*
    What this program does is 
    replace the tabs with proper spaces to the next stop.

    Here's some explanations
    -- Examples 
        abc[TAB]dabcd    abc-----dabcd   
        ab[TAB]cdefgh    ab------cdefgh
        ab[TAB]bcde[TAB] ab----bcde----
    -- Note
        1. The 1st tab is always like '..[TAB]..' (8-N)
    */

    char line[MAXLINE];
    char tline[MAXLINE];

    getln(line, MAXLINE);
    detab(line, tline);

    printf("%s", tline);

    return 0;
}

int getln(char line[], int limit)
{
    /*
    This method is still the same (as the other `getln` impl).
    */

    int c, i;

    i = 0;

    /*
    Just in case you forget..
    -- i < limit - 1    Not beyond the limits 
    -- .. != EOF        Before you exit 
    -- \n               New loop sep by newlines
    */
    while (i < limit - 1 &&
           (c = getchar()) != EOF &&
           c != '\n')
    {
        line[i++] = c;
    }

    if (c == '\n')
    {
        line[i++] = '\n';
    }

    line[i] = '\0';

    return i;
}

void detab(char line[], char tline[])
{
    int i = 0, j = 0;
    int spacew = 0;

    while (line[i] != '\0')
    {
        /*
        Since we've already got the line (by `getln`)
        all we need to do is 
            1. filtering the tabs (& replace it)
            2. not care about any other else 

        The `if .. else` here is just to accomplish this.
        */

        /*
        It produces the right proper amount of spaces.
        Examples
        -- abcd[TAB]            8 - 3 % 8 (=5)    # the 3 is index
        -- abc[TAB]abcded[TAB]  8 - 6 % 8 (=2)    # the 2 is the 2nd
        */
        spacew = TABWIDTH - j % TABWIDTH;

        printf("whileDetab <j = [%2d]>\n", j);

        if (line[i] == '\t')
        {
            /*
            If there's a tab character,
            replace them with proper number of other chars.
            */

            printf("spacew: %d\n", spacew);

            /*
            The `spacew` was being re-defined 
            when it doesn't meets the "right" spaces.
            */
            while (spacew-- > 0)
            {
                tline[j++] = '*';
            }

            ++i;
        }
        else
        {
            // The other chars which is not tab
            //  will be just be assigned from the `line` array.
            tline[j++] = line[i++];

            printf("whileDetabElse tline = [%s]\n", tline);
        }
    }

    if (line[i] == '\n')
    {
        tline[j++] = line[i];
    }

    tline[j] = '\0';
}