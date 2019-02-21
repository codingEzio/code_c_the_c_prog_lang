#include <stdio.h>

#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    /*
    Expected output
    -- input stuff & press Enter => print its len
    -- input stuff .. (same stuff over here)
    -- Press 'ctrl + D' => return the longest line you've input before 

    Those `printf(..[..<..>]..)` is for debugging purposes.
    For now, those are meant to stay for a long time.
    */

    int len;            // current line len
    char line[MAXLINE]; // current input line

    int maxlen;            // maximum len see so far
    char maxline[MAXLINE]; // longest line saved here

    maxlen = 0;

    while ((len = getln(line, MAXLINE)) > 0)
    {
        printf("[Inside<while>]\n");

        if (len > maxlen)
        {
            printf("[Inside<If>]\n");

            maxlen = len;
            copy(maxline, line);
        }

        printf("line_length: %d\n", len);
    }

    if (maxlen > 0)
    {
        // This `if` return the longest line so far.
        printf("\n%s", maxline);
    }

    return 0;
}

int getln(char s[], int limi)
{
    /*
    The whole method is to "concat" a complete string.

    These are some possible cases
    -- Examples 
        abcd\n\0        # 5
        ab\n\0          # 2
        abcdefg\n\0     # 7 (replace 'maxline')
        \n\0            # simplest scenario
    -- Procedures

    */

    // Input | ArrayIndexForCopyInput
    int c, i;

    /*
    These are my assumptions :D
    -- for  =>  create an array to store the input
    -- s[i] =>  copy the input to any array, aka. the `s`

    Also, do notice the `.. && .. & ..`
    -- actually, the `s[i]` may not even run 
    -- cond'll be ture only if { lessThan999|1000, notEOF, notNewline } !
    
    The most important part is the `getchar()`
    -- since it only can get ONE char at a time,
    -- that's why we need to use a `while/for` to loop all the strs.
    */
    for (i = 0;
         i < limi - 1 && (c = getchar()) != EOF && c != '\n';
         ++i)
    {
        printf("[Inside<getLnFor]\n");
        s[i] = c;
    }

    // Possible scenarios
    // -- '\n' only
    // -- '\n' after typing lots of characters
    if (c == '\n')
    {
        printf("[Inside<getLnIf>]\n");
        s[i] = c; // not input anything, just a newline ('\n')
        ++i;      // it's still being considered as one char not 0!
    }

    // Okay,
    //    this is specifically for char arrays
    //    e.g. Hello <=> ['H', 'e', 'l', 'l', 'o', '\0']
    // Also,
    //    it will eventually produce a string (either `for` or `if`)
    //    so this line is just add an "ending" (C specific of course)
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        printf("Inside<CopyWhile>\n");
        ++i;
    }
}
